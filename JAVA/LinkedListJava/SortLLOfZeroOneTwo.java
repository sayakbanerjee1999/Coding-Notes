/*
class Node
{
    int data;
    Node next;
    Node(int data)
    {
        this.data = data;
        next = null;
    }
}
*/
class Solution
{
    //Function to sort a linked list of 0s, 1s and 2s.
    static Node segregate(Node head)
    {
        // add your code here
        //array of size 3 for storing number of 0s, 1s and 2s.
        int count[] = new int[3];
        Node temp = head;
        //traverse and store respective count
        while(temp!=null){
            count[temp.data]++;
            temp = temp.next;
        }
        //make temp back to head
        temp = head;
        int i = 0;
        while (temp!=null){
            if (count[i]==0)
            //if all 0/1/2 have been sorted  together then increment i
                i++;
            else{
                //set the node value to i and decrement count of that respestive
                temp.data = i;
                count[i]--;
                //add to linked list 
                temp = temp.next;
            }
        }
        return head;
    }
}
