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
private:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
public:
    void inorder(TreeNode* root){
        if (root == NULL) return;

        inorder(root->left);

        // Inorder travsersal should be increasing
        // Anomaly if curr val < prev val
        if(prev!=NULL && root->val < prev->val){
            // Captures the first wrong value
            if(!first){
                first = prev;
                middle = root;
            }
            // Captures the second wrong value
            else {
                last = root;
            }
        }

        // Important Step. Update Previous
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};
