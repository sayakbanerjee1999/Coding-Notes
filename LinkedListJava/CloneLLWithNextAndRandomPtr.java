/*
class Node {
    int data;
    Node next, arb;

    Node(int d) 
    { 
        data = d;
        next = arb = null; 
        
    }
}*/

class Clone {
    //Function to clone a linked list with next and random pointer.
    Node copyList(Node head) {
        // your code here
        Node newHead = null;
        Node curr = head;
        //first step: copy all the original nodes
        //1->2 ------ 1->1->2->2
        while (curr!=null){
            //new node
            Node temp = new Node(curr.data);
            //join with prev
            temp.next = curr.next;
            //move
            curr.next = temp;
            curr = curr.next.next;
        }
        //second step: now establish the random pointers for the copied nodes
        curr = head;
        while (curr!=null){
            //if random ptr exists
            if (curr.arb!=null)
                curr.next.arb = curr.arb.next;
            curr = curr.next.next;
        }
        //third step: make all the connections
        curr = head;
        while (curr!=null){
            //backup
            Node temp = curr.next;
            //for the first node
            if (newHead==null)
                newHead = temp;
            curr.next = curr.next.next;
            if (temp.next!=null)
            //if original exists then duplicate also present
                temp.next = temp.next.next;
            curr = curr.next;
        }
        //return the new head
        return newHead;
    }
}
