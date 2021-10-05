/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


class Solution {
       public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;
        //if value is lesser search for node in right tree
        if(root.val < key){
            root.right = deleteNode(root.right, key);
        //if value is greater search for node in left tree
        }else if(root.val > key){
            root.left = deleteNode(root.left, key);
        }else{
            if(root.left != null && root.right != null){
              //find max in the left subtree and replace it with the key node and then delete that node
                int v = findmax(root.left, Integer.MIN_VALUE);
                root.val = v;
                root.left = deleteNode(root.left, v);
                return root;
            }else if(root.left != null){  //if right tree is empty return left
                return root.left;
            }else if(root.right != null){ //if left tree is empty return right
                return root.right;
            }else{
                return null;
            }
            
        }
        return root;
    }
    
    //findidng max in the left subtree - the max is the rightmost node of any subtree of BT type
    private static int findmax(TreeNode root, int max){
       while(root !=null){
           max = Math.max(max, root.val);
           root = root.right;
       }
        return max;
    }
}
