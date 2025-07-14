class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjL(n);
        for(auto it: flights)
            adjL[it[0]].push_back({it[1], it[2]});
        
        queue<pair<int, pair<int, int>>> q;     // {stops, {node, fare}}
        // Stops as the first element because you want to bound it
        vector<int> fares(n, 1e9);
        // Stops always increase by 1 (constant number)
        // Hence, not required to maintain a pq -> q suffices 
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int fare = it.second.second;

            if(stops > k)
                continue;
            
            for(auto i: adjL[node]){
                int newLoc = i.first;
                int currFare = i.second;

                // You can reach the final destination with stops = k+1
                // Bcoz stops are the intermediary locs. 
                if(fare+currFare<fares[newLoc] && stops<=k){
                    fares[newLoc] = fare+currFare;
                    q.push({stops+1, {newLoc, fare+currFare}});
                }
            }
        }

        if(fares[dst]==1e9) return -1;
        return fares[dst];
    }
};
