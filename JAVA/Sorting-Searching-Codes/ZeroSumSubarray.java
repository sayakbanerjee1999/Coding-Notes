class Solution{
    //Function to count subarrays with sum equal to 0.
    public static long findSubarray(long[] arr ,int n) 
    {
        //Your code here
        //logic: if two subparts have sum = X then the subpart in between these two will have sum = 0
        //so we will keep count of the frequency of the sums that are occuring with every ele addition
        //checking if sum is present already then wowzaa we found a zero subarray
        long count = 0;
        int i = -1;
        long sum = 0;
        //hashmap keeping count of the number of times every sum is coming
        HashMap<Long,Long> mp = new HashMap<Long,Long>();
        //initial setup
        mp.put(0L,1L);
        while(i<n-1){
            i++;
            sum += arr[i];
            //check if sum is present
            if (mp.containsKey(sum)){
                //add the frequency of sum to count
                count+=mp.get(sum);
                mp.put(sum, mp.get(sum)+1);
            } else {
                mp.put(sum,1L);
            }
        }
        return count;
    }
}
