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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(TreeNode* root, int& diameter){
        if(!root)
            return 0;
        
        int lHeight = height(root->left, diameter);
        int rHeight = height(root->right, diameter);

        // Checks Diameter = lHeight + rHeight for every node
        // and keeps track of the maximum
        diameter = max(diameter, lHeight+rHeight);

        // Return Height till for a node
        return 1 + max(lHeight, rHeight);
    }
};
