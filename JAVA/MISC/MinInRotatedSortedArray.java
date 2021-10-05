public class Solution {
    //using binary search approach 
    public int findMin(int[] num) {
        //base condition check
        if (num == null || num.length == 0) {
            return 0;
        }
        //if only 1 length
        if (num.length == 1) {
            return num[0];
        }
        //start and end pointers for BS
        int low = 0;
        int high = num.length - 1;
        while(low < high){
            int mid = (low + high) / 2;
            //if mid element is greater then end then search in the second half else the first half
            if(num[high] < num[mid]){
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return num[high];
    }
}

