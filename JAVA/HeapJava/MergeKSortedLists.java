/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists==null || lists.length==0)
            return null;
        
        //Priority Q of listnodes to compare the linked list by their head values in minheap
        //it will contain k eles list.length hence and compare lowest first
        PriorityQueue<ListNode> pq = new PriorityQueue<>(
        lists.length,(a,b) -> a.val-b.val);
        
        //Setup output list pointer
        ListNode temp = new ListNode(0);
        ListNode tail = temp;
        
        //Adding all the linkedlist to the pq which will be in order or the smallest value of head of list first
        for (ListNode node : lists){
            if (node!=null)
                pq.add(node);
        }
        
        //start traversing
        while(!pq.isEmpty()){
            //pop, get smallest linked list head and add to the tail.next
            tail.next = pq.poll();
            //make tail point to that curr head right now
            tail = tail.next;
            //again add the remaining part of the list without the head to the pq
            if (tail.next!=null){
                pq.add(tail.next);
            }
        }
        
        //return my start pointer temp
        return temp.next;
    }
}
