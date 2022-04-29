class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int res = INT_MIN;
        solve(root, res);
        
        return res;
    }
    
    int solve(TreeNode* root, int& res){
        if(!root)
            return 0;
        
        int ls = solve(root->left, res);
        int rs = solve(root->right, res);
        
        // IF MAX SUM PASSES THROUGH ROOT. TAKE MAX OF LS / RS
        int temp = max(max(ls, rs) + root->val, root->val);     
        
        // IF MAX SUM PASSES THROUGH ANY SUBTREE
        int ans = max(temp, ls + root->val + rs);
        
        res = max(res, ans);
        
        // PASS ON TEMP VALUE TO PARENT NODE FOR RECURSSION
        return temp;
    }
};
