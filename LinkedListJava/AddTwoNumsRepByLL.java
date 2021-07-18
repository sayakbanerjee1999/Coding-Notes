/* node for linked list

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

*/

class Solution{
    //to reverse a LL
    public static Node reverse(Node head)
    {
        // code here
        Node curr = head;
        Node prev = null;
        //for storing the next node as the link would be lost
        Node temp = null;
        while (curr!=null){
            temp = curr.next;
            //make the link
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    static Node addTwoLists(Node first, Node second){
        // code here
        // return head of sum list
        //reverse and add operations
        first = reverse(first);
        second = reverse(second);
        int sum = 0;
        int carry = 0;
        Node curr = null;
        Node headRef = null;
        while (first!=null||second!=null){
            //compute sum for the digits
            //checking for null before taking data as number of digits for numbers may differ
            if (first!=null && second!=null)
                sum = carry + first.data + second.data;
            else if (first==null & second!=null)
                sum = carry + 0 + second.data;
            else if (first!=null & second==null)
                sum = carry + first.data + 0;
            //if sum>=10 then carry present
            carry = (sum>=10 ? 1:0);
            //to get the last digit and make a new node
            sum = sum%10;
            Node res = new Node(sum);
            //point the new head to res
            if (headRef==null)
                headRef = res;
            else
            //keep linking to res
                curr.next = res;
            //now my curr node is res
            curr = res;
            
            //keep the while moving to cover all the digits of both nums
            if (first!=null)
                first = first.next;
            if (second!=null)
                second = second.next;
            
            }
            //for final carry if any
            if (carry>0){
                Node res = new Node(carry);
                curr.next = res;
                curr = res;
        }
        //return reverse of the new head
        return reverse(headRef);
        
    }
}
