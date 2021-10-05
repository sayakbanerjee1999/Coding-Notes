class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inOrder(Node* root, vector<int> &res){
        if(root==NULL)
            return;
        
        inOrder(root->left, res);
        res.push_back(root->data);
        inOrder(root->right, res);
    }
    
    Node* constructBST(vector<int> nums, int left, int right){
        if(left > right)
            return NULL;
        
        int mid = left + (right-left)/2;
        int rootVal = nums[mid];
        Node* root = new Node(rootVal);
        
        root->left = constructBST(nums, left, mid-1);
        root->right = constructBST(nums, mid+1, right);
        
        return root;
    }
    
    Node *binaryTreeToBST (Node *root){
        //Your code goes here
        vector<int> res;
        
        inOrder(root, res);
        
        sort(res.begin(), res.end());
        
        return constructBST(res, 0, res.size()-1);
    }
};
