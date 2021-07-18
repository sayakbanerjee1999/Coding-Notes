/*
class Node{
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
} 
*/

class Solution
{
    public static Node reverseList(Node head)
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
    public static Node addOne(Node head) 
    { 
        //code here.
        //first reverse the LL and apply the operation on the last digit directly
        //8->9->9
        //reverse it 9->9->8
        head = reverseList(head);
        Node curr = head;
        while (curr!=null){
            if (curr.next==null && curr.data==9){
                //add 1 so 10 curr 1 and 0 new node
                //all 9's have come this far means end of LL add a new node with 0 and change curr to 1
                curr.data = 1;
                Node add = new Node(0);
                add.next = head;
                head = add;
                curr = curr.next;
            }
            else if (curr.data==9){
                //if its not the last node just change it to 0 and go to next
                //0->9->8
                //0->0->8
                curr.data = 0;
                curr=curr.next;
            }
            else if (curr.data!=9){
                //if not 9 then no carry ans reached break
                //0->0->9
                curr.data++;
                curr = curr.next;
                break;
            }
        }
        //return the reverse as we resersed it and computed on it
        //9->0->0
        return reverseList(head);
    }
}
