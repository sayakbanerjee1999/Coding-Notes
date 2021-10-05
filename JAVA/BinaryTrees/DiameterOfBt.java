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
public class Solution {
    int max = 0;
    
    public int diameterOfBinaryTree(TreeNode root) {
        solve(root);
        return max;
    }
    
    private int solve(TreeNode root) {
        if (root == null) return 0;
        
        int left = solve(root.left);
        int right = solve(root.right);
        
        max = Math.max(max, left + right);
        
        return Math.max(left, right) + 1;
    }
}
