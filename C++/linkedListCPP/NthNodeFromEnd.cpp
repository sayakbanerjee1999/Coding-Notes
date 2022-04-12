int getNthFromLast(Node *head, int n)
{
    // Your code here
    if(!head)
        return -1;
    
    int len = 0;
    Node *temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    
    temp = head;
    
    if(n > len)
        return -1;
    
    else{
        int diff = abs(n-len);
        for(int i = 0; i < diff; i++){
            temp = temp->next;
        }
        
        return temp->data;
    }
}
