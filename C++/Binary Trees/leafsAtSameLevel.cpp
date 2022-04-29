class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        if(!root)
            return false;
        
        int checkHeight = -1, height = 0;
        int ans = 1;
        
        solve(root, checkHeight, height, ans);
        
        return ans;
    }
    
    void solve(Node* root, int &checkHeight, int height, int &ans){
        if(!root)
            return;
        
        if (ans == 0)
            return;
            
        //For leaf Node
        if(root->left == NULL  &&  root->right == NULL){
            if(checkHeight == -1)
                checkHeight = height;
            else{
                if(checkHeight != height){
                    ans = 0;
                    return;
                }
            }
        }
        
        if(root->left)
            solve(root->left, checkHeight, height+1, ans);
        if(root->right)
            solve(root->right, checkHeight, height+1, ans);
    }
};
