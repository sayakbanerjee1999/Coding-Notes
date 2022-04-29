Leetcode - 508
  
class Solution {
public:
    unordered_map<int, int> hashmap;
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        hashmap.clear();
        
        vector<int> res;
        if(!root)
            return res;
        
        int maxFrequency = 0;
        solve(root, maxFrequency);
        
        for(auto it: hashmap){
            if(it.second == maxFrequency)
                res.push_back(it.first);
        }
        
        return res;
    }
    
    int solve(TreeNode* root, int &maxFreq){
        if(!root)
            return 0;
        
        int ls = solve(root->left, maxFreq);
        int rs = solve(root->right, maxFreq);
        
        int currSum = ls + root->val + rs;
        
        hashmap[currSum]++;
        
        maxFreq = max(maxFreq, hashmap[currSum]);
        
        return currSum;
    }
};
