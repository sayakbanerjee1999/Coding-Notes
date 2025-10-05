/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Check if Root is p or q then LCA = root
        if(root==NULL || root==p || root==q)
            return root;
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // left subtree does not have any root (p, q) -> so right subtree should contain the LCA
        if(leftLCA==NULL)
            return rightLCA;
        // right subtree does not have any root(p, q) -> so left subtree should contain the LCA
        else if(rightLCA==NULL)
            return leftLCA;
        // both subtrees returned NON NULL. So p is in 1 subtree, q is in another subtree. Hence the root is the LCA. 
        else
            return root;
    }
};
