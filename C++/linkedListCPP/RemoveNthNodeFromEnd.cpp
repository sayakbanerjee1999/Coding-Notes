class Solution {
public:
    // Using Fast and Slow Pointer
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fastPtr = dummy;
        ListNode* slowPtr = dummy;

        // Move the fastPtr by n steps
        for(int i = 0; i < n; i++)
            fastPtr = fastPtr->next;
        
        while(fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        slowPtr -> next = slowPtr->next->next;
        
        return dummy->next;
    }
};
