/*Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

 */

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
    public int widthOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        //create our dequeue to pop null values from both ends and apply level order traversal
        Deque<TreeNode> dq = new LinkedList<>();
        dq.add(root);
        //for the max width
        int max = 1;
        while(!dq.isEmpty()) {
          //pop the left and right null value
            while(!dq.isEmpty() && dq.getFirst() == null )    dq.removeFirst();
            while(!dq.isEmpty() && dq.getLast() == null )    dq.removeLast();
          //update the max width base on the dq size after null trimming from both sides
            max = Math.max(max, dq.size());
            int size = dq.size();
            for(int i =0; i <size; i++) {
                TreeNode temp = dq.poll();
              //if null then add the left and right children null values
                if(temp == null) {
                    dq.add(null);
                    dq.add(null);
                } else {
                  //else if not null then add the child values
                    dq.add(temp.left);
                    dq.add(temp.right);
                }
                
            }
        }
        return max;
    }
}
