class Solution{
    //Function to rotate a linked list.
    //remove the last node pointer to null and make it head
    //make the second last node point to null
    //do this k times
    public Node rotate(Node head, int k) {
        // add code here
        if (head==null)
            return head;
        int len = 0;
        Node temp = head;
        while (temp!=null){
            len++;
            temp = temp.next;
        }
        Node last = head;
        Node secLast = null;
        k = k%len;
        for (int i=0;i<k;i++){
            while (last.next!=null){
                secLast = last;
                last = last.next;
            }
            secLast.next = null;
            last.next = head;
            head = last;
        }
        return head;
    }
}
