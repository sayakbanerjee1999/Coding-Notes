class Solution
{
    public:
    void inOrder(Node *root, vector<int> &res){
        if(root==NULL)
            return;
        
        inOrder(root->left, res);
        res.push_back(root->data);
        inOrder(root->right, res);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> res;
        
        inOrder(root, res);
        
        reverse(res.begin(), res.end());
        return res[K-1];
    }
};
