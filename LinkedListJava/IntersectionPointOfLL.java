/* Node of a linked list
 class Node {
   int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}
 Linked List class
class LinkedList
{
    Node head;  // head of list
}*/

class Intersect
{
    //Function to find intersection point in Y shaped Linked Lists.
	int intersectPoint(Node head1, Node head2)
	{
         // code here
        Node curr1 = head1;
        Node curr2 = head2;
        int len1 = 0;
        int len2 = 0;
        //get the full length of the 2 LL
        while (curr1!=null){
            len1++;
            curr1 = curr1.next;
        }
        while (curr2!=null){
            len2++;
            curr2 = curr2.next;
        }
        //make them point to head again
        curr1 = head1;
        curr2 = head2;
        //to run the internal loop that many num of times for the greater length LL to bring them to same level
        int diff = Math.abs(len1-len2);
        if (len1>len2){
            for (int i=0;i<diff;i++)
                curr1 = curr1.next;
        } else{
            for (int i=0;i<diff;i++)
                curr2 = curr2.next;
        }
    //now check for the intersection
        while (curr1!=curr2){
            curr1 = curr1.next;
            curr2 = curr2.next;
        }
        if (curr1!=null)
            return curr1.data;
        else 
            return -1;
	}
}
