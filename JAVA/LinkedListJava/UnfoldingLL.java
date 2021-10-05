public class Solution{
  //reverse LL
  Node reverseList(Node head)
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
  
  public static void unfold(Node head){
    if (head==null || head.next==null)
      return;
    Node fh = head; //first head
    Node fp = fh;   //first prev
    Node sh = head.next; //second head
    Node sp = sh; //second prev
     
    while (sp!=null && sp.next!=null){
      Node f = sp.next;  //forward node backup
      //make links
      fp.next = f;
      sp.next = f.next;
      //move
      fp = fp.next;
      sp = sp.next;
    }
    //to make 2 list separate
    fp.next = null;
    //reverse the second list
    sh = reverList(sh);
    //add them
    fp.next = sh;
  }
  
}
