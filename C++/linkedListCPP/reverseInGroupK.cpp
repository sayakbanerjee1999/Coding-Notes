class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* curr = head;
        node* prev = NULL;
        node* n = NULL;
        int count = 0;
        
        while(curr != NULL && count < k){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
            count++;
        }
        
        // See that 
        if(curr)
            head->next = reverse(curr, k);
        
        return prev;
    }
};
