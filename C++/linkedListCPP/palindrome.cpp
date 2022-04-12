class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head){
        Node *slowPtr = head;
        Node *fastPtr = head;
        
        while(fastPtr != NULL  &&  fastPtr->next != NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        Node* curr = slowPtr;
        Node* n = NULL;
        Node* prev = NULL;
        
        while(curr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        
        Node *temp = head;
        while(prev != NULL){
            if(temp->data != prev->data)
                return false;
            
            temp = temp->next;
            prev = prev->next;
        }
        
        return true;
    }
};
