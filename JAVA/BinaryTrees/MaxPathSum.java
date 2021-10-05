//Very amazing qns

class Solution {
    int max;
    public int maxPathSum(TreeNode root) {
        max = Integer.MIN_VALUE;
        helper(root);
        return max;
    }
    
    public int helper(TreeNode root){
        if (root==null) return 0;
        // first get the maximum from the left and right subtrees, if negative so dont take hence max compared with 0 :)
        int left = Math.max(0, helper(root.left));
        int right = Math.max(0, helper(root.right));
        //max path of current node by adding left and right subtree with the current node value
        max = Math.max(max,root.val+left+right);
        //most important part is what to send to parent; we cant send max directly as path continuity might be broken as we including both left and right
        //in previous step; so we select max of left and right and subtree, add it with current node value and return to parent to make the path linear
        return Math.max(left,right)+root.val;
    }
}
