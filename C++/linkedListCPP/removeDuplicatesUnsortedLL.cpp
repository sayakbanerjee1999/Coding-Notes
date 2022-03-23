class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates(Node *head) 
    {
        // your code goes here
        if(head == NULL)
            return head;
        
        unordered_map<int, bool> hash;
        Node* curr = head;
        hash[curr->data] = true;
        
        Node* prev = curr;
        curr = curr->next;
        
        while(curr){
            if(hash[curr->data]){
                prev->next = curr->next;
                free(curr);
            }
            
            else{
                hash[curr->data] = true;
                prev = curr;
            }
            
            curr = prev->next;
        }
        
        return head;
    }
};
