Topological Sort/Kahn Algorithm - GFG

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<int> in(V, 0);
	    
	    queue<int> q;
	    
	    for(int i = 0; i < V; i++){
	        for(auto x: adj[i]){
	            in[x]++;
	        }   
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(in[i]==0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        int temp = q.front();
	        res.push_back(temp);
	        q.pop();
	        
	        for(auto x: adj[temp]){
	            in[x]--;
	            if(in[x]==0){
	                q.push(x);
	            }
	        }
	    }
	    
	    return res;
	}
};
