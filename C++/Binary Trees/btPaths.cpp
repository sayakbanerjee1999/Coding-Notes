class Solution {
public:
    void solve(TreeNode* root, vector<string>& paths, string currPath){
        if(!root)
            return;
        
        currPath += to_string(root->val);
        if(root->left == NULL  &&  root->right == NULL){
            paths.push_back(currPath);
        }
        
        
        if(root->left)
            solve(root->left, paths, currPath + "->");
        
        if(root->right)
            solve(root->right, paths, currPath + "->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        
        if(!root)
            return paths;
        
        solve(root, paths, "");
        
        return paths;
    }
};
