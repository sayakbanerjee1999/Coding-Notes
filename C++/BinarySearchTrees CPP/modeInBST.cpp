Leetcode - 501
  
class Solution {
public:
    void solve(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        
        solve(root->left, res);
        res.push_back(root->val);
        solve(root->right, res);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        
        if(!root)
            return res;
        
        solve(root, res);
        
        map<int, int> dict;
        for(int i = 0; i < res.size(); i++){
            if(dict.find(res[i]) == dict.end())
                dict[res[i]] = 1;
            else
                dict[res[i]]++;
        }
        
        int maxFreq = 0;
        for(auto it: dict){
            maxFreq = max(maxFreq, it.second);
        }
        
        vector<int> ans;
        for(auto it: dict){
            if(it.second == maxFreq)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};
