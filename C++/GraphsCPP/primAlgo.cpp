Prim Algorithm to Find the Minimum Spanning Tree in a Graph - GFG

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> inMST(V, false);
        int ans = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        minHeap.push({0, 0});
        
        while(!minHeap.empty()){
            auto best = minHeap.top();
            minHeap.pop();
            
            int dist = best.first;
            int toVertex = best.second;
            
            // If vertex already included in the MST don't do anything;
            if(inMST[toVertex])
                continue;
            
            else{
                inMST[toVertex] = true;
                ans += dist;
                
                //Explore all connected vertecies to this vertex and then add in minHeap if already not in MST
                for(auto v: adj[toVertex]){
                    if(!inMST[v[0]])
                        minHeap.push({v[1], v[0]});             //Insert distance followed by vertex
                }
            }
        }
        
        return ans;
    }
};
