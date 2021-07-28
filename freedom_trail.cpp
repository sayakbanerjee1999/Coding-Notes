class Solution {
public:
    int dp[101][101];
    
    int solve(string ring, string key, int ptr, int index) {
        int n = ring.size();
        int m = key.size();
        
        // If empty string
        if(index >= m)
            return 0;
        
        if(dp[index][ptr] != -1)
            return dp[index][ptr];
        
        int steps = INT_MAX;
        
        // abs(i-ptr) -> smaller path; 
        // n - abs(i-ptr) -> larger path;
        for(int i = 0; i < n; i++) {
            if(ring[i] == key[index]){
                steps = min(steps, min(abs(i-ptr), n-abs(i-ptr)) + 1 + solve(ring, key, i, index+1));
            }
        }
        
        return dp[index][ptr] = steps;
    }
    
    int findRotateSteps(string ring, string key) {
        int ptr = 0;
        int index = 0;
        
        int n = ring.size();
        int m = key.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(ring, key, ptr, index);
    }
};
