class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[][] memo = new int[n+1][amount+1];
        for (int i=0;i<n+1;i++){
            for (int j=0;j<amount+1;j++){
                if (i==0)
                    memo[i][j] = Integer.MAX_VALUE;
                if (j==0)
                    memo[i][j] = 0;
                
            }
        }
        for (int j=1;j<amount+1;j++){
            if (j%coins[0]==0)
                memo[1][j] = j/coins[0];
            else
                memo[1][j] = Integer.MAX_VALUE;
        }
        for (int i=1;i<n+1;i++){
            for (int j=1;j<amount+1;j++){
                if (coins[i-1]<=j)
                    memo[i][j] = Math.min(memo[i][j-coins[i-1]]+1, memo[i-1][j]);
                else
                    memo[i][j] = memo[i-1][j];
            }
        }
        return memo[n][amount] == Integer.MAX_VALUE ? -1 : memo[n][amount];
        
    }
}
