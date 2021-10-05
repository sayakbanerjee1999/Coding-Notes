class Solution
{
    //Function to reverse a linked list.
    Node reverseList(Node head)
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
}
