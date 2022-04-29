Leetcode - 116 (Perfect Binary Tree)

class Solution {
public:
    Node* connect(Node* root) {
        Node* first = root;
        
        if(!first)
            return NULL;
        
        while(first && first->left){
            Node* temp = first;
            
            while(true){
                temp->left->next = temp->right;
                
                if(!temp->next)
                    break;
                
                temp->right->next = temp->next->left;
                
                temp = temp->next;
            }
            
            first = first->left;
        }
        
        return root;
    }
};
