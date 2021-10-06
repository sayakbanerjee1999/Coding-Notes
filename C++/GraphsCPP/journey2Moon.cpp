Journey to the Moon - Hackerrank

void dfs(int src, vector<int> g[], vector<bool> &visited, long long &countNodes){
    visited[src] = 1;
    countNodes++;
    
    for(auto i: g[src]){
        if(!visited[i]){
            dfs(i, g, visited, countNodes);
        }
    }
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    if(n==0)
        return 0;
    
    vector<int> g[n];
    
    for(auto i: astronaut){
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
    
    // Numeber of Nodes in each component
    vector<long long> numberNodes;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            long long countNodes = 0;
            dfs(i, g, visited, countNodes);
            numberNodes.push_back(countNodes);
        }
    }
    
    // nC2 total pairs
    long long res = n;
    res *= n-1;
    res /= 2;
    
    for(int i = 0; i < numberNodes.size(); i++){
        long long x = numberNodes[i];
        x *= (x-1);
        x /= 2;
        res = res - x;
    } 
    
    return res;
}
