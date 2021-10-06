House Robber - LeetCode 198

class Solution {
public:
    int rob(vector<int>& nums) {
        int exc = 0;
        int inc = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int ninc = nums[i] + exc;
            int nexc = max(inc, exc);
            
            exc = nexc;
            inc = ninc;
        }
        
        return max(inc, exc);
    }
};
