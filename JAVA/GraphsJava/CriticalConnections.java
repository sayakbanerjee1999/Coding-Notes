/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 
 */

class Solution 
{
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) 
    {
        //arraylist containing the nodes and the connected neighbours
        Map<Integer, List<Integer>> graph = new HashMap<>();
        //for returning the final answer
        List<List<Integer>> ans = new LinkedList<>();
        for (List<Integer> connection : connections)
        {
            int a = connection.get(0);
            int b = connection.get(1);
            graph.putIfAbsent(a, new LinkedList<>());
            graph.putIfAbsent(b, new LinkedList<>());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        //id values mark all as their i values
        int[] rank = new int[n];
        for (int i = 0; i < n; ++i)
        {
            rank[i] = i;
        }
        //to keep track of visited node
        boolean[] visited = new boolean[n];
        int prevNode = -1, curNode = 0, curRank = 0;
        dfs(visited, rank, prevNode, curNode, curRank, graph, ans);
        return ans;
    }
    
    private void dfs(boolean[] visited, int[] rank, int prevNode, int curNode, int curRank, Map<Integer, List<Integer>> graph, List<List<Integer>> ans)
    {
        //mark node with current ranking and as visited
        rank[curNode] = curRank;
        visited[curNode] = true;
        //go to all its neighbours
        for (int neighbor : graph.get(curNode))
        {
            if (neighbor == prevNode)
                continue;
            //if not visited then run dfs incrementing current rank
            if (!visited[neighbor])
                dfs(visited, rank, curNode, neighbor, curRank + 1,graph,ans);
            //while backtracking select minimum of the ranks
            rank[curNode] = Math.min(rank[curNode], rank[neighbor]);
            //if start rank reached then add as ans
            if (rank[neighbor] == curRank + 1){
                ans.add(Arrays.asList(curNode, neighbor));
            }
        }
    }
}
