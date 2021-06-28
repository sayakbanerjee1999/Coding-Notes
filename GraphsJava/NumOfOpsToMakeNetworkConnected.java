class Solution {
    // Function to visit the nodes of a graph
    public static void DFS(HashMap<Integer, ArrayList<Integer> > adj,
                           int node, boolean visited[])
    {
        // If current node is already visited
        if (visited[node])
            return;
 
        // If current node is not visited
        visited[node] = true;
 
        // Recurse for neighbouring nodes
        for (int x : adj.get(node)) {
 
            // If the node is not vistied
            if (visited[x] == false)
                DFS(adj, x, visited);
        }
    }
    
    // Function to check if it is possible
    // to connect all the computers or not
    public static int makeConnected(int N, int connections[][])
    {
        int M = connections.length;
        // Stores counmt of minimum
        // operations required
        int minOps = makeConnectedUtil(N, connections, M);
 
        // Print the minimum number
        // of operations required
        return minOps;
    }
    
    public static int makeConnectedUtil(int N, int[][] connections,int M) {
        // Stores whether a
        // node is visited or not
        boolean visited[] = new boolean[N];
 
        // Build the adjacency list
        HashMap<Integer, ArrayList<Integer> > adj
            = new HashMap<>();
 
        // Initialize the adjacency list
        for (int i = 0; i < N; i++) {
            adj.put(i, new ArrayList<Integer>());
        }
 
        // Stores count of edges
        int edges = 0;
 
        // Building adjaceny list
        // from the given edges
        for (int i = 0; i < M; ++i) {
 
            // Get neighbours list
            ArrayList<Integer> l1
                = adj.get(connections[i][0]);
            ArrayList<Integer> l2
                = adj.get(connections[i][1]);
 
            // Add edges
            l1.add(connections[i][1]);
            l2.add(connections[i][0]);
 
            // Increment count of edges
            edges += 1;
        }
 
        // Stores count of components
        int components = 0;
 
        for (int i = 0; i < N; ++i) {
 
            // If node is not visited
            if (visited[i] == false) {
 
                // Increment components
                components += 1;
 
                // Perform DFS
                DFS(adj, i, visited);
            }
        }
 
        // At least N - 1 edges are required
        if (edges < N - 1)
            return -1;
 
        // Count redundant edges
        int redundant
            = edges - ((N - 1) - (components - 1));
 
        // Check if components can be
        // rearranged using redundant edges
        if (redundant >= (components - 1))
            return components - 1;
 
        return -1;
    }
}
