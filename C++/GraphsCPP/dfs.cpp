Depth First Search - GFG

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfsUtil(int src, vector<int> adj[], vector<int> &visited, vector<int> &res){
	    visited[src] = 1;
	    res.push_back(src);
	    
	    for(auto x: adj[src]){
	        if(!visited[x])
	            dfsUtil(x, adj, visited, res);
	    }
	}
	
	vector<int> dfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> visited(V, 0);
	    vector<int> res;
	    
	    for(int i = 0; i < V; i++){
	        if(!visited[i])
	            dfsUtil(i, adj, visited, res);
	    }
	    
	    return res;
	}
};
