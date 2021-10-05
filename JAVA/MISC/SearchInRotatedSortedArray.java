class Solution {
    public int search(int[] nums, int target) {
        //using binary search concept
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2; 
            //if target reached
            if (nums[mid] == target) {
                return mid;
            } 
            //if mid value is greater than left 
            else if (nums[mid] >= nums[left]) {
                //if target<mid then search in the left part
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    //else search in the right part
                    left = mid + 1;
                }
            } else {
               //if target is less than nums on right and >mid search in right part else in left
               if (target > nums[mid] && target <= nums[right]) {
                   left = mid + 1;
               }  else {
                   right = mid - 1;
               }
            }
        }
        return -1;
    }
}
