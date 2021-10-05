/*
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        this.data = key;
        next = null;
    }
} */

class Solution
{
    //Function to sort the given linked list using Merge Sort.
    static Node mergeSort(Node head)
    {
        // add your code here
        head = mergeSortHelper(head);
        return head;
    }
    
    static Node mergeSortHelper(Node head){
        if (head==null || head.next==null)
            return head;
        
        //divide into two halves
        Node prev = null, slow = head, fast = head;
        //partition by middle element using slow fast ptrs
        while (fast != null && fast.next != null) {
          prev = slow;
          slow = slow.next;
          fast = fast.next.next;
        }
        
        prev.next = null;
        
        // sort each half recursively
        Node l1 = mergeSortHelper(head);
        Node l2 = mergeSortHelper(slow);
        
        //merge the two halves into one LL
        head = merge(l1,l2);
        return head;
    }
    
    
    static Node merge(Node a, Node b){
        if (a==null)
            return b;
        if (b==null)
            return a;
        Node ans = null;
        //recursive call for merging
        if (a.data<=b.data){
            ans = a;
            ans.next = merge(a.next,b);
        } else{
            ans = b;
            ans.next = merge(a,b.next);
        }
        return ans;
    }    
}
