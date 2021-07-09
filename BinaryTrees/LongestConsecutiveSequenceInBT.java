class Solution
{
    public int result;
	public int longestConsecutive(Node root)
        {
         //add code here.
         if (root==null) return 0;
         result = 0;
         helper(root);
         return result;
         
        }
        
    public int helper(Node root){
        if (root==null) return 0;
        //
        int left = helper(root.left);
        int right = helper(root.right);
        int currMax = 1;
        //
        if (root.left==null || root.left.data==root.data+1)
            currMax = Math.max(left+1,currMax);
        if (root.right==null || root.right.data==root.data+1)
            currMax = Math.max(right+1,currMax);
        //
        result = Math.max(result,currMax);
        //
        return currMax;
    }
}
