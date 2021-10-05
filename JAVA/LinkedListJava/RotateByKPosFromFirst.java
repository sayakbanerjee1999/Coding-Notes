class Solution{
    //Function to rotate a linked list.
    
    public Node rotate(Node head, int k) {
        // add code here
        if (head==null || k==0)
            return head;
            
        Node curr = head;
        //go till the end
        while (curr.next!=null){
            curr = curr.next;
        }
        
        curr.next = head;
        curr = head;
        
        //k-1 will be last element
        for (int i=0;i<k-1;i++){
            curr = curr.next;
        }
        head = curr.next;
        curr.next = null;
        return head;
    }
}
