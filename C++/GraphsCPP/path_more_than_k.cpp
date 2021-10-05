bool solve(int src, int k, vector<bool> &visited, vector<pair<int, int>> g[]){
        visited[src] = true;
        
        if(k<=0)
            return true;
            
        for(auto x: g[src]){
            int v = x.first;
            int w = x.second;
            
            // If visited[v]==true then we are forming a cycle. Don't include
            if(visited[v])
                continue;
            
            if(w>=k)
                return true;
                
            if(solve(v, k-w, visited, g))
                return true;
        }
        
        // Backtrack
        visited[src] = false;
        
        return false;
    }
    
    bool pathMoreThanK(int V, int E, int k, int *a){ 
       //  Code Here
       vector<pair<int, int>> adj[V];
       
       int n = 3*E;
       for(int i = 0; i < n; i=i+3){
           adj[a[i]].push_back({a[i+1], a[i+2]});
           adj[a[i+1]].push_back({a[i], a[i+2]});
       }
       
       vector<bool> visited(V, false);
       
       return solve(0, k, visited, adj);
    }
