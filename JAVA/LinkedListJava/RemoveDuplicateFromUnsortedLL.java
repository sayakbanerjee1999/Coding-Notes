class Solution
{
    //Function to remove duplicates from unsorted linked list.
    public Node removeDuplicates(Node head) 
    {
         // Your code here
         //we can use a hashmap to check whether an element is already present
         HashMap<Integer,Boolean> hm = new HashMap<>();
         //will maintain 2 pointers prev and curr
         Node curr = head;
         Node prev = null;
            
         //start traversing
         while (curr!=null){
             //if already present make prev point to its next skipping it
             if (hm.containsKey(curr.data)){
                 prev.next = curr.next;
             } else{
                 //else add it to hashmap
                 hm.put(curr.data,true);
                 prev = curr;
             }
             //to keep the loop moving
             curr = curr.next;
         }
         return head;
    }
}
