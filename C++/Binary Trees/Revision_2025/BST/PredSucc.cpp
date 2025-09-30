/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    Node* inorderSuc(Node* root, int key){
        Node* successor = NULL;
        
        while(root){
            // Less than key so cannot be a successor move right
            if (root->data <= key){
                root = root->right;
            }
            // Can be a candidate for successor as value is greater than target. 
            // Move left for smaller candidates
            else{
                successor = root;
                root = root->left;
            }
        }
        
        return successor;
    }
    
    Node* inorderPred(Node* root, int key){
        Node* predecessor = NULL;
        
        while(root){
            // More than key cannot be a successor move left
            if(root->data >= key){
                root = root->left;
            }
            // Can be a candidate for predecessor as value is smaller than target
            // But move right for bigger candidates
            else{
                predecessor = root;
                root = root->right;
            }
        }
        
        return predecessor;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(root == NULL) return {NULL};
        
        Node* curr1 = root;
        Node* curr2 = root;
        
        Node* suc = inorderSuc(curr1, key);
        Node* pred = inorderPred(curr2, key);
        
        if(suc == NULL && pred == NULL) return {NULL};
        
        vector<Node*> res(2);
        res[0] = pred;
        res[1] = suc;
        
        return res;
    }
};
