class GfG
{
    //Function to remove duplicates from sorted linked list.
    Node removeDuplicates(Node head)
    {
	// Your code here
	Node curr = head;
	if (head == null){
	    return null;
	    }
  //start traversing
	while (curr.next!=null){
    //if curr data equal to next node data
	    if (curr.data==curr.next.data){
          //make current next point to next's next - skip the next as its duplicate
	        curr.next = curr.next.next;
	    } else{
        //keep traversing
	        curr = curr.next;
	    }
	  }
	  return head;
	}
}
