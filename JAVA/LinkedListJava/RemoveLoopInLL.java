/*
class Node
{
    int data;
    Node next;
}
*/

class Solution
{
    //Function to remove a loop in the linked list.
    public static void removeLoop(Node head){
        // code here
        // remove the loop without losing any nodes
        if (head == null)
            return;
        Node slowPtr = head;
        Node fastPtr = head;
        boolean cycle = false;
        while (fastPtr!=null  && fastPtr.next!=null){
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
            if (slowPtr==fastPtr){
                cycle = true;
                break;
            }
        }
        if (cycle){
            //if starting point of cycle is LL head too
            if (slowPtr==head){
                //take another loop across
                while (fastPtr.next!=slowPtr)
                    fastPtr = fastPtr.next;
                fastPtr.next = null;
            }
            else if (slowPtr==fastPtr){
                //normal processing
                slowPtr = head;
                while (slowPtr.next!=fastPtr.next){
                    slowPtr = slowPtr.next;
                    fastPtr = fastPtr.next;
                }
                fastPtr.next = null;
            }
        }
    }
}
