class Solution {
    public int[] twoSum(int[] nums, int target) {
        //store the diff of target and nums[i] and index
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        int len = nums.length;
        for(int i = 0; i < len; i++){
            //if hashmap contains the num means the other half to add up to the target is already present
            if(hm.containsKey(nums[i])){
                //so return the hm index value and curr index
                int left = hm.get(nums[i]);
                return new int[]{left, i};
            }else{
                hm.put(target - nums[i], i);
            }
        }
        return new int[2];
    }
}
