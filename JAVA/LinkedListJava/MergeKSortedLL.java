/*class Node
{
    int data;
    Node next;
    
    Node(int key)
    {
        data = key;
        next = null;
    }
}
*/

// a is an array of Nodes of the heads of linked lists
// and N is size of array a


class Solution
{
    //Function to merge K sorted linked list.
    Node mergeKList(Node[]arr,int k)
    {
        //Add your code here.
        //using minHeap for approaching this question
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        //push all elements into the min heap
        for (int i=0;i<k;i++){
            Node head = arr[i];
            while (head!=null){
                pq.add(head.data);
                head = head.next;
            }
        }
        Node head = null;
        Node curr = null;
        while (pq.size()!=0){
            if (head==null){
                //for the first node
                head = new Node(pq.poll());
                curr = head;
            } else{
                //for the remaining nodes
                Node temp = new Node(pq.poll());
                curr.next = temp;
                curr = temp;
            }
        }
        return head;
    }
}
