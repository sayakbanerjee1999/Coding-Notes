class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }    
        
        // Memoization
        if(dp[root])
            return dp[root];
        
        // Root Data included
        int inc = root->val;
        
        if(root->left)
            inc += rob(root->left->left) + rob(root->left->right);
        
        if(root->right)
            inc += rob(root->right->left) + rob(root->right->right);
        
        int exc = rob(root->left) + rob(root->right);
        
        dp[root] = max(inc, exc);
        
        return dp[root];
    }
};
