class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        
        bool cycleDetected = false;
        
        while(fastPtr != NULL  &&  fastPtr->next != NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
            if(slowPtr == fastPtr){
                cycleDetected = true;
                break;
            }
        }
        
        //Once Loop is detected.
        //Move slowPtr to head. Now move both ptrs by 1 unit. 
        //The position where both meet is the Starting Point
        if(cycleDetected){
            slowPtr = head;
            while(slowPtr != fastPtr){
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
            
            return slowPtr;
        }
        
        else
            return NULL;
    }
};
