/*You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

 */

class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
      //pass starting and end point
        TreeNode root = construct(nums, 0, nums.length -1);
        return root;
    }
    private static TreeNode construct(int arr[], int s, int e){
      //if start greater than end example: [3,0,1] left of 3 nothing so index 0 and -1 are passed hence 3 made a leaf node
        if(s > e) return null;
      //if start=end leaf node no construction from there
        if(s == e) return  new TreeNode(arr[s]);
        
      //root is max number in the array
        int idx = findMax(arr, s, e);
      //root is the max value index
        TreeNode root = new TreeNode(arr[idx]);
      //index is dividing into left and right parts
        root.left  = construct(arr, s, idx-1);
        root.right = construct(arr, idx+1, e);
        
        return root;
    }
    
    private static int findMax(int arr[], int s, int e){
        int max = Integer.MIN_VALUE;
        int idx = -1;
        for(int i =s; i <=e; i++){
            if(arr[i] >  max){
                max = arr[i];
                idx = i; 
            }
        }
        
        return idx;
    }
}
