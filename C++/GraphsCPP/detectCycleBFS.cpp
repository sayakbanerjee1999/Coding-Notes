Detect Cycle in an undirected Graph using BFS - GFG

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool dfs(int src, int par, vector<int>& visited, vector<int> adj[]){
	    visited[src] = 1;
	    
	    for(auto x: adj[src]){
	        if(!visited[x]){
	            bool check = dfs(x, src, visited, adj);     //src is the parent of x
	            
	            if (check == true)
	                return true;
	        }
	        
	        else if(visited[x] && par!=x)       //If not parent node but comes back comes back again cycle is there
	            return true;
	    }
	    
	    return false;
	}
	
	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    vector<int> visited(V, 0);
	    
	    //First for each vertex individually (This condition is required for disconnected graphs)
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){
	            bool check = dfs(i, -1, visited, adj);      //-1 is the parent of the first node
	            
	            if(check==true)
	                return true;
	        } 
	    }
	    
	    return false;
	}
};
