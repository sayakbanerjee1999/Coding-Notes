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
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        calculateSum(root, pathSum);
        return pathSum;
    }

    int calculateSum(TreeNode* root, int& pathSum){
        if(!root)
            return 0;

        // Do not take a negative sum at any step
        int lSum = max(0, calculateSum(root->left, pathSum));
        int rSum = max(0, calculateSum(root->right, pathSum));

        // pathSum keeps track of maxsum at all nodes
        pathSum = max(pathSum, lSum+root->val+rSum);

        // Current Node will return the max of (Left/Right Sum)
        // along with its own val to previous node
        // Similar to how height is return
        return root->val+ max(lSum,rSum);
    }
};
