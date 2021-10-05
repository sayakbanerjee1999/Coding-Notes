//User function Template for Java

/* A Binary Tree node
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/

class Solution
{
    public ArrayList<Integer> arr = new ArrayList<>();

    boolean isLeaf(Node root){
        
        
        if(root.left == null && root.right == null)
            return true;
        return false;
    }
    boolean check(Node root)
    {
	// Your code here
		 
	 checkSameLevel(root,0,arr);
     boolean flag = true;
     int first = arr.get(0);

     for (int i = 1; i< arr.size(); i++)
     {
        if(arr.get(i) != first) {
            flag = false;
            break;
        }
     }
     return flag;
    }
    
    void checkSameLevel(Node root, int level, ArrayList<Integer> arr){
	    if (root==null)
	        return;
	    if(isLeaf(root)){
	        arr.add(level);
	    }
	    if(root.left != null)
	    checkSameLevel(root.left, level+1, arr);
	    if(root.right != null)
	    checkSameLevel(root.right, level+1, arr);
	    
	    
    }
}
