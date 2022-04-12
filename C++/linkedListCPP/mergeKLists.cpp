class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minH;
        int size = lists.size();
        
        for(int i = 0; i < size; i++){
            ListNode* head = lists[i];
            
            while(head){
                minH.push(head->val);
                head = head->next;
            }
        }
        
        ListNode *head_ref = NULL;
        ListNode *curr = NULL;
        
        while(!minH.empty()){
            if(head_ref == NULL){
                ListNode *temp = new ListNode(minH.top());
                minH.pop();
                head_ref = temp;
                curr = head_ref;
            }
            
            else{
                ListNode *temp = new ListNode(minH.top());
                minH.pop();
                curr->next = temp;
                curr = temp;
            }
        }
        
        return head_ref;
    }
};
