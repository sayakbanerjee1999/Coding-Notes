public class Solution{
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i=0; i< nums.length-2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {              // skip same result
                continue;
            }
            //initialize the two pointers for 2 sum on each of i element
            int low = i + 1, high = nums.length - 1;  
            //now my target sum is -ith value
            int target = -nums[i];
            while (low < high) {
                if (nums[low] + nums[high] == target) {
                    //add it to result
                    res.add(Arrays.asList(nums[i], nums[low], nums[high]));
                    //check for duplicates too for low -> low +1 check as low moving forwards and vice versa for high
                    while (low < high && nums[low] == nums[low + 1]) low++;  // skip same result
                    while (low < high && nums[high] == nums[high - 1]) high--;  // skip same result
                    low++;
                    high--;
                } else if (nums[low] + nums[high] > target) {
                    //if higher than target then decrement high value as list sorted already
                    high--;
                } else {
                    low++;
                }
            }
        }
        return res;
    }
}
