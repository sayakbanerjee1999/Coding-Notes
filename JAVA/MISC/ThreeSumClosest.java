class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int diff = Integer.MAX_VALUE;
        
        for (int i = 0; i < nums.length; i++) {
            //initializing 2 pointers
            int left = i + 1;
            int right = nums.length - 1;
            
            while (left < right) {
                //getting sum at that position
                int sum  = nums[i] + nums[left] + nums[right];
                
                //updating the differenc value
                if (Math.abs(target - sum) < Math.abs(diff)) {
                    diff = target - sum;
                }
                
                //if greater than search in left side else right
                if (sum > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        //return the closest sum
        return (target-diff);
    }
}
