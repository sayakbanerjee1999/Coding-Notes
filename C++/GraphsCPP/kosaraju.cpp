Kosaraju Algorithm to Find Strongly Connected Components - GFG

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	vector<int> order;
	
	void dfs(int src, vector<bool> &vis, vector<int> adj[]){
	    vis[src] = true;
	    
	    for(auto i: adj[src]){
	        if(!vis[i])
	            dfs(i, vis, adj);
	    }
	    
	    order.push_back(src);
	}
	
	void rdfs(int src, vector<bool> &visited, vector<int> adj[]){
	    visited[src] = true;
	    
	    for(auto i: adj[src]){
	        if(!visited[i])
	            dfs(i, visited, adj);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[]){
        //code here
        order.clear();
        
        vector<int> revAdj[V];
        for(int i = 0; i < V; i++){
            for(auto x: adj[i]){
                revAdj[x].push_back(i);
            }
        }

        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
        
        vector<bool> rvis(V, false);
        int count = 0;
        for(int i = order.size()-1; i >= 0; i--){
            if(!rvis[order[i]]){
                rdfs(order[i], rvis, revAdj);
                count++;
            }
        }
        
        return count;
    }
};
