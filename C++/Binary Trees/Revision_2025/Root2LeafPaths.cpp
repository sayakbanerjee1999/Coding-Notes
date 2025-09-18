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
    void helper(TreeNode* node, vector<string> &res, string op){
        if(!node)
            return;
        
        op += to_string(node->val);

        // If leaf node one traversal complete so push back
        if(!node->left && !node->right){
            res.push_back(op);
        }

        else{
            helper(node->left, res, op+"->");
            helper(node->right, res, op+"->");
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        helper(root, res, "");

        return res;
    }
};
