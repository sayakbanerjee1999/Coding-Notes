/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;

        while(fastPtr && fastPtr->next){
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }

        return slowPtr;
    }

    ListNode* merge2LL(ListNode* first, ListNode* second){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(first && second){
            if(first->val <= second->val){
                temp->next = first;
                first = first->next;
            }
            else{
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }

        if(first) temp->next = first;
        else temp->next = second;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
  
        ListNode* middle = findMiddle(head);       // Use fastPtr slowPtr; slowPtr = head; fastPtr = head->next
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* first = head;
    
        ListNode* left_ = sortList(first);
        ListNode* right_ = sortList(right);

        return merge2LL(left_, right_);
    }
};
