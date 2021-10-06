Bellman Ford Algorith - GFG 

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dis(V, 100000000);
        dis[S] = 0;
        
        // Relax for (V-1) times (Check Abdul Bari)
        for (int i = 0; i < V - 1; i++){
            
            // Check for all connected components
            for(int j = 0; j < adj.size(); j++) {
                int u = adj[j][0];
                int v = adj[j][1];
                int w = adj[j][2];
                
                if (dis[u]!=1e8 && dis[u]+w<dis[v])
                    dis[v] = dis[u] + w;
            }
        }
        
        return dis;
    }
};
