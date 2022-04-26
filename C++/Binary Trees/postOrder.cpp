class Solution {
public:
    void solve(TreeNode* root, vector<int>& res){
        if(root == NULL)
            return;
        
        solve(root->left, res);
        solve(root->right, res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if(!root)
            return res;
        
        solve(root, res);
        
        return res;
    }
};
