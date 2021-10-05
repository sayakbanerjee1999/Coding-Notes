/*Node class  used in the program
class Node
{
	int data;
	Node next;
	Node bottom;
	
	Node(int d)
	{
		data = d;
		next = null;
		bottom = null;
	}
}
*/
/*  Function which returns the  root of 
    the flattened linked list. */
class GfG
{
    Node flatten(Node root)
    {
	// Your code here
	//making use of bottom and next pointer
	//start flattening from right two
	if (root==null || root.next==null)
	    return root;
	return merge(root,flatten(root.next));
    }
    
    Node merge(Node first, Node second){
        if (first==null)
            return second;
        if (second==null)
            return first;
        Node res;
        //merging happening downward
        if (first.data<second.data){
            res = first;
            res.bottom = merge(first.bottom, second);
        } else{
            res = second;
            res.bottom = merge(first,second.bottom);
        }
        res.next = null;
        return res;
    }
    
    
}
