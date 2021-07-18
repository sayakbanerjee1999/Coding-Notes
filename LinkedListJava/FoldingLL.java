/*class Node
{
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
}*/

class gfg {
    
    Node reorderlist(Node head) {
        if (head==null || head.next==null)
            return head;
            
        //get the middle node
        //divide the LL into 2 parts from mid
        Node mid = midNode(head);
        Node nextHead = mid.next;
        mid.next = null;
        
        //reverse the second half of the LL
        nextHead = reverseList(nextHead);
        //now lets begin main part
        Node c1 = head;
        Node c2 = nextHead;
        Node f1 = null;
        Node f2 = null;
        
        while (c2!=null){
            //backup of both lists
            f1 = c1.next;
            f2 = c2.next;
            //make the links
            c1.next = c2;
            c2.next = f1;
            //move
            c1 = f1;
            c2 = f2;
        }
        return head;
    }
    
    //reversing LL
    Node reverseList(Node head)
    {
        // code here
        Node curr = head;
        Node prev = null;
        //for storing the next node as the link would be lost
        Node temp = null;
        while (curr!=null){
            //take backup
            temp = curr.next;
            //make the link
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    //finding mid node
    Node midNode(Node head) {
        // Your code here
        if (head==null || head.next==null)
            return head;
        Node slowPtr = head;
        Node fastPtr = head;
        //break the LL into 2 parts from middle
        while (fastPtr.next!=null && fastPtr.next.next!=null){
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }
        //slowPtr will hold LL mid
        return slowPtr;
    }
}
