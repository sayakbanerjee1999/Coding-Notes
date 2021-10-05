class Solution {

    // arr[] : the input array containing 0s and 1s
    // N : size of the input array
    
    // return the maximum length of the subarray
    // with equal 0s and 1s
    int maxLen(int[] arr, int N)
    {
        // Your code here
        //same sum means; in between subarray has equal num of 0s and 1s received
        int ans = 0;
        //storing sum and index ; treat 0 as -1 and 1 as 1
        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(0,-1);
        //for keeping the sum at each index
        int sum = 0;
        for (int i=0;i<arr.length;i++){
            //if 0 add -1 - logic of the code
            if (arr[i]==0){
                sum+=-1;
            } else if (arr[i]==1){
                sum+=1;
            }
        
            if (hm.containsKey(sum)){
                //if map contains sum, get the index and the length and update ans
                int idx = hm.get(sum);
                int len = i-idx;
                ans = Math.max(ans, len);
            } else{
                hm.put(sum,i);
            }
        }
        return ans;
    }
}
