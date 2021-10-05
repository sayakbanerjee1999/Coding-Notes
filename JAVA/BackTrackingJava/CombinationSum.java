/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.*/

class Solution {
    List<List<Integer>> ans;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int n = candidates.length;
        int k = target;
        ans = new LinkedList<>();
        helper(new ArrayList<Integer>(), n, k, candidates);
        return ans;
    }
    
    public void helper(List<Integer> inner, int i, int target, int[] nums) {
      //sum reached so add to o/p 
      if (target==0) {
            ans.add(new ArrayList<>(inner));
            return;
        } 
      //reached beg of the array
        if (i==0) {
            return;
        }    
      //if curr > target, then go to earlier index
        if (target < nums[i-1]) {
            helper(inner, i-1, target, nums);
        } else {
          //if curr<target then sum can be possible, add to list inner
            inner.add(nums[i-1]);
          //recurse for remaining including the curr index with new target value
            helper(inner, i, target-nums[i-1], nums);      
          //backtrack condition
            inner.remove(inner.size()-1);
          //call again for remaining ; concept of unbounded knapsack
            helper(inner, i-1, target, nums);
        }
    }
}
