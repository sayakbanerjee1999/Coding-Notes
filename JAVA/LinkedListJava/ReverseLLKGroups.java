class Solution
{
    public static Node reverse(Node node, int k)
    {
        //Your code here
        //base case
        if (node==null || k==1)
            return node;
        Node curr = node;
        Node prev = null;
        Node temp = null;
        int count = 0;
        while (curr!=null && count<k){
            temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        if(curr!=null){
            node.next = reverse(curr,k);
        }
        return prev;
    }
}
