Detect Cycle in Directed Graph using DFS - GFG 

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfsUtil(int src, vector<int> adj[], vector<int> &visited, vector<int> &order){
	    visited[src] = 1;
	    order[src] = 1;
	    
	    for(auto x: adj[src]){
	        if(!visited[x]){
	            bool check = dfsUtil(x, adj, visited, order);
	            
	            if(check == true)
	                return true;
	        }
	        
	        // Already visited and lies in path of cycle
	        else if(visited[x]==1 && order[x]==1)
	            return true;
	    }
	    
	    order[src] = 0;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<int> order(V, 0);
	   	vector<int> visited(V, 0);
	   	
	   	for(int i = 0; i < V; i++){
	   	    if(!visited[i]){
	   	        bool check = dfsUtil(i, adj, visited, order);
	   	        
	   	        if(check == true)
	   	            return true;
	   	    }
	   	}
	   	
	   	return false;
	}
};
