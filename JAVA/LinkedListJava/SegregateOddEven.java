class Solution{
    Node divide(int N, Node head){
        // code here
        Node evenStart = null;
        Node evenEnd = null;
        Node oddStart = null;
        Node oddEnd = null;
        Node currentNode = head;
         
        while(currentNode != null) {
            int element = currentNode.data;
            //if even
            if(element % 2 == 0) {
                //if first even then make it currenNode and make it the Even end
                if(evenStart == null) {
                    evenStart = currentNode;
                    evenEnd = evenStart;
                } else {
                    //if not first even, normal linking
                    evenEnd.next = currentNode;
                    evenEnd = evenEnd.next;
                }
                 
            } else {
                //if odd
                //if first odd
                if(oddStart == null) {
                    oddStart = currentNode;
                    oddEnd = oddStart;
                } else {
                    //if not first odd
                    oddEnd.next = currentNode;
                    oddEnd = oddEnd.next;
                }
            }
        // Move head pointer one step in forward direction to run the while loop
            currentNode = currentNode.next;   
        }
         
         
        if(oddStart == null || evenStart == null) {
            return head;
        }
        //linking the odd and even together 
        evenEnd.next = oddStart;
        oddEnd.next = null;
        head=evenStart;
        return head;
    }
}
