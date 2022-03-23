class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenStart = NULL;
        ListNode* evenEnd = NULL;
        ListNode* oddStart = NULL;
        ListNode* oddEnd = NULL;
        ListNode* curr = head;
        
        int index = 1;
        while(curr){
            if(index % 2 == 0){
                if(evenStart == NULL){
                    evenStart = curr;
                    evenEnd = curr;
                }
                
                else{
                    evenEnd->next = curr;
                    evenEnd = curr;
                }
            }
            
            else{
                if(oddStart == NULL){
                    oddStart = curr;
                    oddEnd = curr;
                }
                
                else{
                    oddEnd->next = curr;
                    oddEnd = curr;
                }
            }
            
            curr = curr->next;
            index++;
        }
        
        if(oddStart == NULL  ||  evenStart == NULL)
            return head;
        
        ListNode* head_ref = oddStart;
        oddEnd->next = evenStart;
        evenEnd->next = NULL;
        
        return head_ref;
    }
};
