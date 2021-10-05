class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        
        if (nums == null || nums.length == 0) return result;
        
        List<Integer> current = new ArrayList<Integer>();
        result.add(current);
        
        recursiveFunc(result, current, 0, nums);
        
        return result;
    }
    
    private void recursiveFunc(List<List<Integer>> res, List<Integer> current, int currentIndex, int[] nums) {
        if (currentIndex >= nums.length) return;
        
        for (int i = currentIndex; i < nums.length; i++) {
            List<Integer> copy = new ArrayList<Integer>(current);
            copy.add(nums[i]);
            res.add(copy);
            recursiveFunc(res, copy, i + 1, nums);
        }
    }
}
