int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> g(n);
    
    for(auto i: flights){
        g[i[0]].push_back({i[1], i[2]});
    }
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    
    minHeap.push({0, src, 0});
    
    set<string> visited;
    
    while(!minHeap.empty()){
        auto best = minHeap.top();
        minHeap.pop();
        
        int cost = best[0];
        int destination = best[1];
        int stops = best[2];
        
        if(dst == destination)
            return cost;
          
         //Continue Exploration
        if(stops <= k){
            for(auto j: g[destination]){
                minHeap.push({cost+j.second, j.first, stops+1});
            }
        }    
    }
    
    return -1;
}
