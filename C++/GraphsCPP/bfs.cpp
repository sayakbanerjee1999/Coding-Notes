Breadth First Search - GFG

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> res;
	    vector<int> visited(V, 0);
	    queue<int> q;
	    
	    q.push(0);
	    
	    visited[0] = 1;
	    
	    while(!q.empty()){
	        int temp = q.front();
	        res.push_back(temp);
	        
	        for(auto x: adj[temp]){
	            if(!visited[x]){
	                visited[x] = 1;
	                q.push(x);
	            }
	        }
	        
	        q.pop();
	    }
	    
	    return res;
	}
};
