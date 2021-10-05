/* Node of a linked list
 class Node {
   int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}
*/

class Sol
{
   public static Node findIntersection(Node head1, Node head2)
    {
        // code here.
        //for the final ans
        Node headRef = null;
        Node curr = null;
        Node curr1 = head1;
        Node curr2 = head2;
        while (curr1!=null && curr2!=null){
            //make use of sorted lists
            if (curr1.data<curr2.data)
            //move first ahead
                curr1 = curr1.next;
            else if (curr2.data<curr1.data)
            //move second ahead
                curr2 = curr2.next;
            else if (curr1.data == curr2.data){
                //if equal intersection node found
                Node res = new Node(curr1.data);
                //if first node 
                if (headRef==null)
                    headRef = res;
                else
                //link it
                    curr.next = res;
                curr = res;
                //keep loop moving
                if (curr1!=null)
                    curr1 = curr1.next;
                if (curr2!=null)
                    curr2 = curr2.next;
            }
        }
        return headRef;
    }
}
