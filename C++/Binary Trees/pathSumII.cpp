class Solution {
public:
    void solve(vector<vector<int>>& paths, TreeNode* root, int targetSum,
               vector<int> currPath){
        if(!root)
            return;
        
        currPath.push_back(root->val);
        if(root->left == NULL  &&  root->right == NULL && targetSum == root->val){
            paths.push_back(currPath);
            return;
        }
        
        if(root->left)
            solve(paths, root->left, targetSum - root->val, currPath);
        if(root->right)
            solve(paths, root->right, targetSum - root->val, currPath);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> currPath;
        
        if(!root)
            return paths;
        
        solve(paths, root, targetSum, currPath);
        
        return paths;
    }
};
