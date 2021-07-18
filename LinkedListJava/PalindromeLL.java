
/* Structure of class Node is
class Node
{
	int data;
	Node next;
	
	Node(int d)
	{
		data = d;
		next = null;
	}
}*/

class Solution
{
    //Function to check whether the list is palindrome.
    boolean isPalindrome(Node head) 
    {
        //Your code here
        //find middle element using slow and fast ptrs
        Node slowPtr = head;
        Node fastPtr = head;
        while (fastPtr!=null && fastPtr.next!=null){
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }
        Node prev = null;
        Node next = null;
        Node curr = slowPtr;
        //middle element is in curr now
        //now reverse the other side of the linkedlist
        while (curr!=null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        Node temp = head;
        //now check for palindrome condition
        while (prev!=null){
            if (temp.data!=prev.data)
                return false;
            temp = temp.next;
            prev = prev.next;
        }
        return true;
    }    
}
