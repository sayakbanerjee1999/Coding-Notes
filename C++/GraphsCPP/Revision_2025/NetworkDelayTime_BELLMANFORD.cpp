class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // USING BELLMAN FORD
        // vector<int> dist(n+1, 1e9);
        // dist[k] = 0;

        // for(int i = 0; i < n-1; i++){
        //     for(auto it: times){
        //         int u = it[0];
        //         int v = it[1];
        //         int t = it[2];

        //         if(dist[u]!=1e9 && dist[u]+t<dist[v])
        //             dist[v]=dist[u]+t;
        //     }
        // }

        // for(int i = 1; i < n+1; i++){
        //     if(dist[i]==1e9)
        //         return -1;
        // }

        // return *max_element(dist.begin()+1, dist.end());
        // USING DJIKSTRA
        vector<vector<pair<int, int>>> adjL(n+1);
        for(auto it: times){
            adjL[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        dist[k] = 0;
        minH.push({0, k});

        while(!minH.empty()){
            int currTime = minH.top().first;
            int currNode = minH.top().second;
            minH.pop();

            for(auto it: adjL[currNode]){
                int t = it.second;
                int nxtNode = it.first;

                int newT = currTime+t;
                if(newT < dist[nxtNode]){
                    dist[nxtNode] = newT;
                    minH.push({newT, nxtNode});
                }
            }
        }

        for(int i = 1; i < n+1; i++){
            if(dist[i]==1e9)
                return -1;
        }

        return *max_element(dist.begin()+1, dist.end());
    }
};
