Travelling Salesman - GFG

class Solution {
public:
int total_cost(vector<vector<int>>cost){
    // Code here
    int V = cost.size();
    int start = 0;
    
    vector<int> vertex;
    
    for(int i = 0; i < V; i++){
        if(i!=start)
            vertex.push_back(i);
    }
    
    int minPath = INT_MAX;
    
    do{
        int currPath = 0;
        
        int k = start;
        for(int i = 0; i < vertex.size(); i++){
            currPath += cost[k][vertex[i]];
            k = vertex[i];
        }
        
        //Include cost from last point to starting point
        currPath += cost[k][start];
        
        minPath = min(minPath, currPath);
    }
    while(next_permutation(vertex.begin(), vertex.end()));
    
    return minPath;
}
};
