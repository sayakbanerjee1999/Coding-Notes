class Solution {
    //Function to check if the linked list has a loop.
    public static boolean detectLoop(Node head){
        // Add code here
        //using Floyd Cycle Detection
        Node slowPtr = head;
        Node fastPtr = head;
        while (fastPtr!=null && fastPtr.next!=null){
            //inc slow by 1
            slowPtr = slowPtr.next;
            //inc fast by 2
            fastPtr = fastPtr.next.next;
            //if they meet means cycle is present
            if (slowPtr==fastPtr)
                return true;
        }
        return false;
    }
}
