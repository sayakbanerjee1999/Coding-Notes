class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(!head)
            return;
        
        Node* slowPtr = head;
        Node* fastPtr = head;
        bool cycleDetected = false;
        
        while(fastPtr != NULL  &&  fastPtr->next != NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
            if(slowPtr == fastPtr){
                cycleDetected = true;
                break;
            }
        }
        
        if(cycleDetected){
            // Case 1: if loop starts from head (Move FastPtr till FastPtr->next != slowPtr)
            if(slowPtr == head){
                while(fastPtr->next != slowPtr){
                    fastPtr = fastPtr->next;
                }
                
                fastPtr->next = NULL;
            }
            
            //Case 2: From any other point
            else if(slowPtr == fastPtr){
                slowPtr = head;
                
                while(slowPtr->next != fastPtr->next){
                    slowPtr = slowPtr->next;
                    fastPtr = fastPtr->next;
                }
                
                fastPtr->next = NULL;
            }
        } 
    }
};
