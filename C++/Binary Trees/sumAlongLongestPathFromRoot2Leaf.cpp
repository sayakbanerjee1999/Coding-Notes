class Solution
{
public:
    void solve(Node* root, int sum, int depth, int &maxSum, int &maxDepth){
        if(root==NULL)
            return;
        
        // For leaf node
        if(root->left==NULL && root->right== NULL && depth>=maxDepth){
            maxDepth = depth;
            maxSum = sum + root->data;
            return;
        }
        
        if(root->left)
            solve(root->left, sum+root->data, depth+1, maxSum, maxDepth);
        if(root->right)
            solve(root->right, sum+root->data, depth+1, maxSum, maxDepth);
    }
    
    int sumOfLongRootToLeafPath(Node *root){
        //code here
        int sum = 0, maxSum = 0;
        int depth = 0, maxDepth = 0;
        
        solve(root, sum, depth, maxSum, maxDepth);
        
        return maxSum;
    }
};
