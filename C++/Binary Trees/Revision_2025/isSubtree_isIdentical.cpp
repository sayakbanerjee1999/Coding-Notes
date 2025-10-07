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
    bool isSame(TreeNode* s, TreeNode* t){
        if(!s && !t) return true;
        if(!s || !t) return false;

        return ((s->val == t->val) && (isSame(s->left, t->left)) && isSame(s->right, t->right));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;                // Reached end of s, not found
        
        if (isSame(s, t)) return true;       // Current node matches t
        
        // Otherwise, recursively check left and right subtrees
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
