class Solution {
    public int rob(TreeNode root) {
        if (root==null) return 0;
        Map<TreeNode,Integer> map = new HashMap<>();
        return helper(root,map);
    }
    public int helper(TreeNode root, Map<TreeNode,Integer> map){
        //if no house to rob
        if (root==null) 
            return 0;
        //if already computed for this root then just return it
        if (map.containsKey(root))
            return map.get(root);
        
        //if not robbing the current then can rob its children - left n right
        int excludeCurr = helper(root.left, map) + helper(root.right, map);
        //if we rob the current then profit will be curr rob + robs off the grandchildren
        int includeCurr = root.val;
        int a=0, b=0;
        if (root.left!=null)
            a = helper(root.left.left, map) + helper(root.left.right, map);
        if (root.right!=null)
            a = helper(root.right.left, map) + helper(root.right.right, map);
        includeCurr = includeCurr + a + b;
        
        //max will be max of robbing curr or skipping it
        int maxCurr = Math.max(includeCurr, excludeCurr);
        //store before returning
        map.put(root,maxCurr);
        return maxCurr;
    }
}



//OR


public class Solution {
    public int rob(TreeNode root) {
        int[] num = dfs(root);
        return Math.max(num[0], num[1]);
    }
    private int[] dfs(TreeNode x) {
        if (x == null) return new int[2];
        int[] left = dfs(x.left);
        int[] right = dfs(x.right);
        int[] res = new int[2];
        res[0] = left[1] + right[1] + x.val;
        res[1] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return res;
    }
}







