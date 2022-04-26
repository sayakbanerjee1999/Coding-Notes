class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        
        return max(lDepth, rDepth) + 1;
    }
};
