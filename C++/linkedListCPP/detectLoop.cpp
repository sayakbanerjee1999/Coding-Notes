class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(!head)
            return NULL;
            
        Node *fastPtr = head;
        Node *slowPtr = head;
        
        while(fastPtr != NULL  &&  fastPtr->next != NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
            if(slowPtr == fastPtr)
                return true;
        }
        
        return false;
    }
};
