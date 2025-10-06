class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head){
        if(!head)
            return NULL;
            
        struct Node* curr = head;
        struct Node* n = NULL;
        struct Node* prev = NULL;
        
        while(curr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        
        int carry = 0, sum = 0;
        
        struct Node *head_ref = NULL;
        struct Node *curr = NULL;
        
        while(first != NULL || second != NULL){
            sum = carry + (first ? first->data: 0) + (second ? second->data: 0);      // Check if first/second present add data else add 0
            carry = sum >= 10? 1: 0;
            
            sum %= 10;                                                                // Find last digit of sum
            struct Node *res = new Node(sum); 
            
            if(head_ref == NULL)
                head_ref = res;
            
            else
                curr->next = res;
            
            curr = res;
            
            if(first)
                first = first->next;
            
            if(second)
                second = second->next;
        }
        
        // If still carry remaining add a new Node with its value  
        if(carry > 0){
            struct Node* res = new Node(carry);
            curr->next = res;
            curr = res;
        }
        
        curr->next = NULL;
        
        return reverse(head_ref);
    }
};


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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* first = l1;
//         ListNode* second = l2;
//         ListNode* headRef = NULL;
//         ListNode* curr = NULL;
//         int sum = 0;
//         int carry = 0;
        
//         while(first || second){
//             sum = carry + (first? first->val: 0) + (second? second->val: 0);
//             carry = sum / 10;

//             int digit = sum%10;
//             ListNode* tmp = new ListNode(digit);
//             if (headRef == NULL){
//                 headRef = tmp;
//                 curr = headRef;
//             } else {
//                 curr->next = tmp;
//                 curr = tmp;
//             }

//             if(first)
//                 first = first->next;
//             if(second)
//                 second = second->next;
//         }

//         if(carry>0){
//             ListNode* carryNode = new ListNode(carry);
//             curr->next = carryNode;
//             curr = carryNode;
//         }

//         return headRef;
//     }
// };
