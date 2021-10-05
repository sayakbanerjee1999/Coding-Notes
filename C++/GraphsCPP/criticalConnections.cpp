LEETCODE - 1192 (Hard)
Finding Bridge using Tarjan Algorithm

class Solution {
public:
    void dfs(int u, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<int> &parent, vector<vector<int>> &res){
        static int time = 0;
        disc[u] = low[u] = time;
        time++;
        
        for(auto v: adj[u]){
            if(disc[v] == -1){
                parent[v] = u;
                dfs(v, adj, disc, low, parent, res);
                low[u] = min(low[u], low[v]);
                
                if(low[v] > disc[u]){           // It is a bridge
                    res.push_back({u, v});
                }
            }
            
            else if(parent[u] != v){
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> disc(n, -1), low(n, -1), parent(n, -1);
        vector<vector<int>> res;
        
        
        for(int i = 0; i < n; i++){
            if(disc[i] == -1){          // Not yet Discovered
                dfs(i, adj, disc, low, parent, res);
            }
        }
        
        return res;
    }
};
