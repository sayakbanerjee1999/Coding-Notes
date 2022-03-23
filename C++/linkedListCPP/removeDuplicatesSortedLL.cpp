Node *removeDuplicates(Node *head){
    // your code goes here
    if(head == NULL)
        return head;
    
    Node* curr = head;
    while(curr->next){
        if(curr->data == curr->next->data){
            curr->next = curr->next->next;
        }
        
        else{
            curr = curr->next;
        }
    }
    
    return head;
}
