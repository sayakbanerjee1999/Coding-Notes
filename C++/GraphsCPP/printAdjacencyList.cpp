class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> graph;
        
        for(int i = 0; i < V; i++){
            vector<int> res;
            res.push_back(i);
            
            for(auto x: adj[i]){
                res.push_back(x);
            }
            
            graph.push_back(res);
        }
        
        return graph;
    }
};
