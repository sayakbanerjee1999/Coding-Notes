class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++){
            // Removing the duplicate wrt to i
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int l = i + 1;
            int r = n - 1;
            int x = nums[i];
            
            while(l < r){
                if(x + nums[l] + nums[r] == 0){
                    res.push_back(vector<int>{x, nums[l], nums[r]});
                    
                    // Removing the Duplicates wrt l and r
                    while (l < r && nums[l] == nums[l+1]) 
                        l++;
                    
                    while (l < r && nums[r] == nums[r-1]) 
                        r--;
                    
                    l++;
                    r--;
                }
                
                else if(x + nums[l] + nums[r] < 0){
                    l++;
                }
                
                else
                    r--;
            }
        }
        
        return res;
    }
};
