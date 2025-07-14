class Solution {
  // Solution has both set and pq -
  // Complexity (E log V) -> log V due to PQ
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adjL(V);
        
        for(int i = 0; i < edges.size(); i++){
            adjL[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjL[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        set<pair<int, int>> st;          // Like minH set also keeps in ascending order of first ele   
        vector<int> dist(V, 1e9);
        
        // minH.push({0, src});
        st.insert({0, src});
        dist[src] = 0;
        
        while(!st.empty()){
            // int currDist = minH.top().first;
            // int node = minH.top().second;
            // minH.pop();
            
            auto it = *st.begin();
            int currDist = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it: adjL[node]){
                int weightDist = it.second;
                int currNode = it.first;
                
                int updatedDist = currDist + weightDist;
                if(updatedDist < dist[currNode]){
                    // dist[currNode] = updatedDist;
                    // minH.push({updatedDist, currNode});

                    // The only change from minH to set is to delete the previous entry in set
                    // Before Updating or pushing in set check if an entry for this node already exists
                    // Easiest way is to check if dist of node != 1e9 then someone else already touched it
                    if(dist[currNode] != 1e9)
                        st.erase({dist[currNode], currNode});
                    
                    dist[currNode] = updatedDist;
                    st.insert({updatedDist, currNode});
                }
            }
        }
        
        return dist;
    }
};
