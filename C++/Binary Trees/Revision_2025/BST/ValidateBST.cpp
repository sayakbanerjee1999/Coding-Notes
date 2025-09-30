/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Every Node should be in a particular range to be a valid BST
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }

    bool helper(TreeNode* root, auto minVal, auto maxVal){
        if (root==NULL) return true;

        // Strictly check if lies in range otherwise return statement executed
        if (root->val <= minVal || root->val >= maxVal) return false;
        
        return (helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal));
    }
};
