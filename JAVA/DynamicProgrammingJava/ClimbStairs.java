class Solution {
    public int climbStairs(int n) {
        //a space to cache our solutions
        int[] memo = new int[n+1];
        //base cases in recursion replaced by following base cases
        memo[0] = 1;
        memo[1] = 1;
        return recurse(n, memo);
    }
    public int recurse(int n, int[] memo){
        if (memo[n]>0)
            return memo[n];
        int currWays = recurse(n-1, memo)+recurse(n-2, memo);
        memo[n] = currWays;
        return currWays;
    }
}
