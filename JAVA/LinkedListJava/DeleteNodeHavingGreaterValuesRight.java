/*
class Node {
   int data;
   Node next;

  Node(int data) {
      this.data = data;
  }
}
*/
class Solution
{
    //reverse a LL
    Node reverse(Node head)
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
    
    Node compute(Node head)
    {
        // your code here
        head  = reverse(head);
        Node curr = head;
        //start checking from RHS and check with maxR value
        int maxRight = curr.data;
        Node prev = curr;
        curr = curr.next;
        //start traversing from end
        while (curr!=null){
            if (curr.data>=maxRight){
                //update maxR qvalue
                maxRight = curr.data;
                prev = curr;
                curr = curr.next;
            } else{
                //remove the greater element
                prev.next = curr.next;
                curr = prev.next;
            }
        }
        return reverse(head);
    }
}
