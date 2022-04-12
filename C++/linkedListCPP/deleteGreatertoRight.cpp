class Solution
{
    public:
    Node* reverse(Node * head){
        if(!head)
            return NULL;
            
        Node* curr = head;
        Node* n = NULL;
        Node* prev = NULL;
        
        while(curr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        
        return prev;
    }
    
    
    Node *compute(Node *head){
        // your code goes here
        head = reverse(head);
        Node *curr = head;
        
        int maxR = curr->data;
        Node *prev = curr;
        curr = curr->next;
        
        while(curr){
            if(curr->data >= maxR){
                maxR = curr->data;
                prev = curr;
                curr = curr->next;
            }
            
            else{
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        }
        
        return reverse(head);
    }
    
};
