class Solution {
public:
    void combinationSumHelper(int index, vector<int> &candidates, 
                            int target, vector<vector<int>> &res, vector<int> curr){
        if(index == candidates.size()){
            if(target==0){
                res.push_back(curr);
            }
            return;
        }

        // Pick if element at index <= target
        if(candidates[index]<=target){
            curr.push_back(candidates[index]);
            // Can pick multiple times
            combinationSumHelper(index, candidates, 
                                target-candidates[index], res, curr);
            // Backtrack
            curr.pop_back();
        }
        
        // Non-Pick Option is always available
        combinationSumHelper(index+1, candidates, target, res, curr);
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        vector<int> curr;
        combinationSumHelper(0, candidates, target, res, curr);
        return res;
    }
};
