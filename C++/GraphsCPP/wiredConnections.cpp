Number of Operations to Make Network Connected - LeetCode 1319
  
class Solution {
public:
    void dfsUtil(int src, vector<int> adj[], vector<int> &visited){
        visited[src] = 1;
        
        for(auto x: adj[src]){
            if(!visited[x])
                dfsUtil(x, adj, visited);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        int m = connections.size();
        
        if(m < n-1)
            return -1;
        
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> visited(n, 0);
        int countConnected = 0;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                countConnected++;
                dfsUtil(i, adj, visited);
            }
        }
        
        return countConnected-1;
    }
};
