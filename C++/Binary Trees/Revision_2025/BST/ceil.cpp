class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        Node* curr = root;
        int res = -1;
        while(curr){
            if(curr->data == x){
                res = x;
                break;
            }
            else if(curr->data > x){
                res = curr->data;
                // Now look for smaller values
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        
        return res;
    }
};
