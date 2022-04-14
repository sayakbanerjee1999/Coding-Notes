class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head_ref = NULL;
        Node* curr = head;
        
        while(curr){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }
        
        curr = head;
        while(curr){
            if(curr->random)
                curr->next->random = curr->random->next;
            
            curr = curr->next->next;
        }
        
        curr = head;
        while(curr){
            Node *temp = curr->next;
            
            if(head_ref == NULL)
                head_ref = temp;
            
            curr->next = curr->next->next;
            
            if(temp->next)
                temp->next = temp->next->next;
            
            curr = curr->next;
        }
        
        return head_ref;
    }
};
