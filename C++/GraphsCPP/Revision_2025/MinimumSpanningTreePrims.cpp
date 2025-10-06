class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        
        vector<int> visited(V, 0);
        pq.push({0, 0});
        int total_cost = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int weight = it.first;
            
            // If already visited[node]. Do not do anything
            if(visited[node]) continue;
            visited[node] = 1;
            total_cost += weight;
            
            for(auto it: adj[node]){
                // Checking for visited is optional as you already do a continue.
                // But might help you reduce unwanted loops
                if(!visited[it.first])
                    pq.push({it.second, it.first});
            }
        }
        
        return total_cost;
        
    }
};
