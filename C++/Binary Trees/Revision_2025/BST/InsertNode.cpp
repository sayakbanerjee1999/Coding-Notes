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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode* curr = root;

        // Iterative Solution
        while(true){
            // Move right if insertion node has higher value
            if(curr->val<=val){
                // If right node is not null move to it. Move once. Then again the outside loop will execute based on the new condition of curr node
                if(curr->right!=NULL) curr = curr->right;
                else{
                    TreeNode* temp = new TreeNode(val);
                    curr->right = temp;
                    break;
                }
            }
            else{
                // If left node is not null move to it. Move once. Then again the outside loop will execute based on the new condition of curr node
                if(curr->left!=NULL) curr = curr->left;
                else{
                    TreeNode* temp = new TreeNode(val);
                    curr->left = temp;
                    break;
                }
            }
        }

        return root;
    }
};
