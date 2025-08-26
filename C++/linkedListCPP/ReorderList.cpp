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
    void reorderList(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;

        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode* tmp = slowPtr->next;
        slowPtr->next = NULL;

        // Reverse 2nd Half (starting from tmp) 
        // Reverse so that you can traverse backwards now
        ListNode* n = NULL;
        ListNode* prev = NULL;
        ListNode* curr = tmp;
        while(curr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }

        // Now rewire the connections
        ListNode* first = head;
        ListNode* second = prev;
        while(second){    //Logically 2nd half will always be shorter or equal length
            ListNode* n1 = first->next;
            ListNode* n2 = second->next;
            first->next = second;
            second->next = n1;
            first = n1;
            second = n2;
        }
    }
};
