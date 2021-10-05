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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        //at start, considering the entire list to 0 to end-1
        return helper(0,0,inorder.length-1,preorder,inorder);
    }
    //for preorder array we would only need the preStart index but for inorder 
    //array we need both start and end indices to get the segment
    public TreeNode helper(int preStart, int inStart, int inEnd, int[] preorder, int[] inorder){
        if (preStart>preorder.length-1 || inStart>inEnd)
            return null;
        //to get the node we are currently on
        TreeNode root = new TreeNode(preorder[preStart]);
        int indexFound = 0;
        //getting the root value
        for (int i=inStart;i<=inEnd;i++){
            if (inorder[i]==root.val)
                indexFound = i;
        }
        //for left subtree search left of inorder and one next to in preorder
        //for right subtree search in right part of inorder, and skip the 
        //nodes of the left subtree number of which is given by inFound-inStart+1
        root.left = helper(preStart+1, inStart, indexFound-1, preorder, inorder);
        root.right = helper(preStart+indexFound-inStart+1, indexFound+1, inEnd, preorder, inorder);
        return root;
    }
}
