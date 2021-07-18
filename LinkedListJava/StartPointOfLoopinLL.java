/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
  //using floyd algo
  //first check for cycle
    public ListNode detectCycle(ListNode head) {
        if (head == null)
            return head;
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        boolean cycle = false;
        while (fastPtr!=null  && fastPtr.next!=null){
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
            if (slowPtr==fastPtr){
                cycle = true;
                break;
            }
        }
      //if cycle seen then increment slow and fast by 1 - proven where they meet then thats the start point
        if (cycle){
            slowPtr = head;
            while (slowPtr!=fastPtr){
                slowPtr = slowPtr.next;
                fastPtr = fastPtr.next;
            }
            return slowPtr;
        } else 
            return null;
    }
}
