// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        Node* curr = root;
        int res = -1;
        
        while(curr){
            if(curr->data == x){
                res = x;
                break;
            }
            else if(curr->data > x){
                curr = curr->left;
            }
            else{
                res = curr->data;
                // Now look for bigger values
                curr = curr->right;
            }
        }
        
        return res;
    }
};
