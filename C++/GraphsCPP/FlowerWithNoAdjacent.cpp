class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        vector<int> ans(n);
        
        for(auto i: paths){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i = 1; i <= n; i++){
            
            // Initally all colors are available 
            vector<int> color(5, 0);
            
            for(auto a: adj[i]){
                // Ans stores the color of the node with which it is painted
                // Visit all adjacent nodes and mark color as '1' i.e., not available
                color[ans[a-1]] = 1;
            }
            
            for(int j = 1; j <= 4; j++){
                //If any color is available assign
                if(color[j]==0){
                    ans[i-1] = j;
                    break;
                }
            }
        }
        
        return ans;
    }
};
