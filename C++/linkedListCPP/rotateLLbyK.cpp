class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        
        ListNode* temp = head;
        int length = 0;
        
        while(temp){
            length++;
            temp = temp->next;
        }
        
        k = k % length;
        
        for(int i = 0; i < k; i++){
            ListNode* secLast = NULL;
            ListNode* last = head;    
        
            while(last->next){
                secLast = last;
                last = last->next;
            }

            secLast->next = NULL;
            last->next = head;
            head = last;
        }
        
        return head;
    }
};
