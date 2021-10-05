class Solution
{
    //Function to find the maximum money the thief can get.
    public int FindMaxSum(int hval[], int n)
    {
        // Your code here
        if (n == 0)
        return 0;
        if (n == 1)
            return hval[0];
        if (n == 2)
            return Math.max(hval[0], hval[1]);
  
        // dp[i] represent the maximum value stolen
        // so far after reaching house i.
        int[] dp = new int[n];
  
        // Initialize the dp[0] and dp[1]
        dp[0] = hval[0];
        dp[1] = Math.max(hval[0], hval[1]);
  
        // Fill remaining positions
        for (int i = 2; i<n; i++)
            dp[i] = Math.max(hval[i]+dp[i-2], dp[i-1]);
  
        return dp[n-1];
        
    }
}
