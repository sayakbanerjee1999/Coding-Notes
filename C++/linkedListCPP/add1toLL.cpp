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
    
    Node* addOne(Node *head) 
    {
        if(!head)
            return NULL;
            
        head = reverse(head);
        Node *curr = head;
        
        while(curr){
            if(curr->next == NULL  &&  curr->data == 9){
                curr->data = 1;
                Node* add = new Node(0);
                add->next = head;
                head = add;
                // curr = curr->next;
            }
            
            else if(curr->data == 9){
                curr->data = 0;
                // curr = curr->next;
            }
            
            else{
                curr->data++;
                break;
            }
            
            curr = curr->next;
        }
        
        return reverse(head);
    }
};
