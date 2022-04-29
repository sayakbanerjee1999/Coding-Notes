If Root->data == leftSum + rightSum and left Subtrees, right Subtrees are individually sum Trees then the binary tree is said to be a sum tree. 
An empty tree is SumTree. 
If the root is the only node in the BT (ie, no left or right child ie, it is a leaf Node) it is also a SumTree 

class Solution
{
    public:
    int sum(Node* root){
        if(!root)
            return 0;
        
        return sum(root->left) + root->data + sum(root->right);
    }
    
    bool isSumTree(Node* root)
    {
        // Your code here
        if(!root)
            return true;
        
        if(root->left == NULL  &&  root->right == NULL)
            return true;
        
        int ls = sum(root->left);
        int rs = sum(root->right);
        
        if(root->data == ls + rs  &&  isSumTree(root->left) == true  &&  isSumTree(root->right) == true)
            return true;
        else
            return false;
    }
};
