class Solution {
    // The logic here is number of ways to reach Point C = Ways[Point A] + Ways[PointB]
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto it: roads){
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }

        // Consider ways to reach node 0 is 1 (Otherwise it will never update other nodes)
        vector<int> ways(n, 0); 
        ways[0] = 1;

        // Using LONG LONG to avoid overflowing errors
        vector<long long> distance(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long, int>>> pq;
        pq.push({0, 0});
        distance[0] = 0;

        int mod = int(1e9+7);

        while(!pq.empty()){
            long long currDis = pq.top().first;
            int parentNode = pq.top().second;
            pq.pop();

            for(auto it: adjList[parentNode]){
                int wt = it.second;
                int nn = it.first;

                long long newDis = wt + currDis;
                
                // If newDis < distance[nn] -> reaching node of the first time -> assign ways = ways of parent node
                if(newDis < distance[nn]){
                    distance[nn] = newDis;
                    pq.push({newDis, nn});

                    ways[nn] = ways[parentNode];
                }

                // We have already previously neared nn with the same distance. So, now ways[nn] = ways[nn] + ways[parentNode]. However since you have already reached the node with same distance no need to push to pq again.
                else if(distance[nn]!=1e9 && newDis == distance[nn]){
                    ways[nn] = (ways[nn] + ways[parentNode]) % mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};
