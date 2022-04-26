class Solution {
public:
    void solve(TreeNode* root, vector<int>& res){
        if(root == NULL)
            return;
        
        res.push_back(root->val);
        solve(root->left, res);
        solve(root->right, res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if(!root)
            return res;
        
        solve(root, res);
        
        return res;
    }
};
