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
    public int[] findFrequentTreeSum(TreeNode root) {
        //storing node sum till point and the frequency of sum occurence
        HashMap<Integer, Integer> hm = new HashMap<>();
        //main stufffzzz
        helper(root, hm);
      
        //just a list for storing the max frequency sum (hashmap key not the value) from the hashmap, can be multiple most frequents too
        List<Integer> res = new ArrayList<>();
        int max = Integer.MIN_VALUE;
        for(Map.Entry<Integer, Integer> entry:hm.entrySet())
            //if greater than max value get the frequency
            if(entry.getValue() > max){
                max = entry.getValue();
                res.clear();
                res.add(entry.getKey());
            }
        else if(entry.getValue() == max ){
            res.add(entry.getKey());
        }
        //int array for returning
        int[] result = new int[res.size()];
        for(int i  = 0 ; i < res.size(); i++){
            result[i] = res.get(i);
        }
        return result;
    }
    
    //filling up hashmap
    public int helper(TreeNode root, HashMap<Integer, Integer> hm){
        
        if(root == null){
            return 0;
        }
        //if reached a child node then add its value and return to prev step
        if(root.left == null && root.right == null){
           hm.put(root.val, hm.getOrDefault(root.val, 0)+1);
            return root.val;
        }
        
        int sum = root.val;
        if(root.left != null){
          //adding sum recursively
            sum += helper(root.left, hm);
        }
        if(root.right != null){
            sum += helper(root.right, hm);
        }
      //put the recursive sum value to hashmap
        hm.put(sum, hm.getOrDefault(sum, 0)+1);
        return sum;
    }
}
