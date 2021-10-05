class Solution {
public:
    TreeNode* constructBST(vector<int> preorder, int start, int end){
    if (start > end) {
        return NULL;
    }
 
    TreeNode* node = new TreeNode(preorder[start]);
    
    int i;
    for (i = start; i <= end; i++){
        if (preorder[i] > node->val) {
            break;
        }
    }
 
    node->left = constructBST(preorder, start + 1, i - 1);
    node->right = constructBST(preorder, i, end);
 
    return node;
}
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL;
        
        int n = preorder.size();
        return constructBST(preorder, 0, n-1);
    }
};
