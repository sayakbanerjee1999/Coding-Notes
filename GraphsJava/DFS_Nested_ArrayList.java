class Solution
{
  //recursive DFS function
    public ArrayList<Integer> DFS(int curr, boolean visited[], ArrayList<Integer> res, ArrayList<ArrayList<Integer>> adj)
    {
        // Mark the current node as visited and print it
        visited[curr] = true;
        res.add(curr);
 
        // Recur for all the vertices adjacent to this
        // vertex
        ArrayList<Integer> n = adj.get(curr);
        Iterator i = n.iterator();
        while (i.hasNext())
        {
            int nextNode = (Integer)i.next();
            if (!visited[nextNode])
                DFS(nextNode, visited, res,adj);
        }
        return res;
    }
    
    //Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj)
    {
        // Code here
        //Make the visited array for keeping track of nodes visited
        boolean visited[] = new boolean[V];
        //Create the arraylist to finally return
        ArrayList<Integer> res = new ArrayList<Integer>();
        return DFS(0,visited,res,adj);
    
    }
}
