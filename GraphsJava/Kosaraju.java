class Solution
{
    //Function to find number of strongly connected components in the graph.
    public int kosaraju(int N, ArrayList<ArrayList<Integer>> adj)
    {
        //code here
        Stack<Integer> stack = new Stack<Integer>();
        boolean[] visited = new boolean[N];
        for (int i=0;i<N;i++){
            if (visited[i]==false){
                 dfs(adj,visited,i,stack);
            }
        }
        //to get the new graph with edges reversed to proceed to step 2
        ArrayList<ArrayList<Integer>> newGraph = transpose(N,adj);
        
        //Now applying dfs second time in specific order acc to stack and new graph
        visited = new boolean[N];
        int count = 0;
        while (stack.size()>0){
            int current = stack.pop();
            if (visited[current]==false){
                dfs(newGraph,visited,current);
                count++;
            }
        }
        return count;
    }
    
    
    //Step 1 filling stack based on end time : put in before backtracking
    public static void dfs(ArrayList<ArrayList<Integer>> graph, boolean[] visited, int curr, Stack<Integer> stack){
        visited[curr] = true;
        for (int neighbour:graph.get(curr)){
            if (visited[neighbour]==false){
                dfs(graph,visited,neighbour,stack);
            }
        }
        stack.push(curr);
    }
    
    public static void dfs(ArrayList<ArrayList<Integer>> graph, boolean[] visited, int curr){
        visited[curr] = true;
        for (int neighbour:graph.get(curr)){
            if (visited[neighbour]==false){
                dfs(graph,visited,neighbour);
            }
        }
    }
    
    public static ArrayList<ArrayList<Integer>> transpose(int N, ArrayList<ArrayList<Integer>> graph){
        ArrayList<ArrayList<Integer>> result = new ArrayList<>(); 
        for (int i=0;i<N;i++){
            result.add(new ArrayList<>());
        }
        for (int i=0;i<N;i++){
            for (int nbrs:graph.get(i)){
                result.get(nbrs).add(i);
            }
        }
        return result;
    }
    
}
