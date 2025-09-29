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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> set;

        // Keep pointer to index of root in inorder
        for(int i = 0; i < inorder.size(); i++){
            set[inorder[i]] = i;
        }

        TreeNode* root = helper(preorder, 0, preorder.size()-1, 
                                inorder, 0, inorder.size()-1,
                                set);

        return root;
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                     vector<int>& inorder, int inStart, int inEnd, 
                     map<int, int>& set){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inorderRootPos = set[root->val];

        int nodesLeft = inorderRootPos - inStart;
        
        // Main logic here
        // Note PreEnd index
        root->left = helper(preorder, preStart+1, preStart + nodesLeft,
                            inorder, inStart, inorderRootPos-1, set);
        // Note PreStart Index
        root->right = helper(preorder, preStart+nodesLeft+1, preEnd,
                             inorder, inorderRootPos+1, inEnd, set);

        return root; 
    }
};
