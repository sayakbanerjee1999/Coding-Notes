Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *head_ref = NULL;
    Node *curr = NULL;
    
    while(head1 != NULL  &&  head2 != NULL){
        if(head1->data < head2->data)
            head1 = head1->next;
        
        else if(head2->data < head1->data)
            head2 = head2->next;
        
        else if(head1->data == head2->data){
            Node *res = new Node(head1->data); 
            if(head_ref == NULL)
                head_ref = res;
            
            else
                curr->next = res;
            
            curr = res;
            
            if(head1)
                head1 = head1->next;
            
            if(head2)
                head2 = head2->next;        
        }
    }
    
    return head_ref;
}
