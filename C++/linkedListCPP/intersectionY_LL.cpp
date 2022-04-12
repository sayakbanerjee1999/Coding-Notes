int intersectPoint(Node* head1, Node* head2)
{
    Node *curr1 = head1, *curr2 = head2;
    int len1 = 0, len2 = 0;
    
    while(curr1){
        len1++;
        curr1 = curr1->next;
    }
    
    while(curr2){
        len2++;
        curr2 = curr2->next;
    }
    
    int diff = abs(len1 - len2);
    curr1 = head1, curr2 = head2;
    
    if(len1 > len2){
        for(int i = 0; i < diff; i++)
            curr1 = curr1->next;
    }
    
    else{
        for(int i = 0; i < diff; i++)
            curr2 = curr2->next;
    }
    
    while(curr1 != curr2){
        curr1 = curr1->next;
        curr2 = curr2->next;
        
        if(curr1 == curr2){
            return curr1->data;
        }
    }
    
    return -1;
}
