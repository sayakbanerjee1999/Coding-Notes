Check if given graph is Bipartite - LeetCode 785
  
class Solution {
public:
    int flag = 0;
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<int> color(n, -1);
        
        flag = 0;
        for(int i = 0; i < n; i++){
            if(color[i] == -1){                 //Not Colored
                dfs(i, 0, 1, adj, color);
            }
        }
           
        return (flag)?0: 1;
    }
    
    void dfs(int src, int par, int col, vector<int> adj[], vector<int> &color) {
        color[src] = col;
        for(auto it : adj[src]) {
            if(color[it] == -1)               //Not colored. Recurse from adjacent
                dfs(it, src, 3 - col, adj, color);
            else if(it != par and col == color[it]) {     
                flag = 1;
                break;
            }
        }
    }
};
