class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> curr = new ArrayList<Integer>();
        helper(root,targetSum,curr,res);
        return res;
    }
    public void helper(TreeNode root, int sum, List<Integer> curr, List<List<Integer>> res){
        //base case
        if (root==null) return;
        
        curr.add(root.val);
        
        //add the path found to main result 
        if (root.left==null && root.right==null && root.val==sum)
            res.add(new ArrayList(curr));
        
        //traverse for the left and the Right subtrees with the sum value                 //decreased in both cases
        helper(root.left, sum-root.val, curr, res);
        helper(root.right, sum-root.val, curr, res);
        
        //Clean up the list to go to previous step for next computation backtracking
        curr.remove(curr.size()-1);
    }
}
