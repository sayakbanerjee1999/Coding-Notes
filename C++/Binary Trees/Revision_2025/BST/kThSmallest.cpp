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
    // Using the property that Inorder traversal of a BST is always sorted
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> res;
    //     inorder(root, res);

    //     return res[k-1];
    // }

    // void inorder(TreeNode* root, vector<int> &res){
    //     if(root==NULL) return;

    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }

    // Without Extra Space
    int kthSmallest(TreeNode* root, int k){
        int res;
        int count = 0;
        inorder(root, k, count, res);
        return res;
    }

    void inorder(TreeNode* root, int k, int &count, int &res){
        if(root == NULL) return;

        inorder(root->left, k, count, res);

        // Store the value in the reference pointer when in the inorder step of printing
        count += 1;
        if(count == k){
            res = root->val;
            return;
        }

        inorder(root->right, k, count, res);
    }
};


// To find kth largest just do reverse inorder -> node->right, print, node->left
