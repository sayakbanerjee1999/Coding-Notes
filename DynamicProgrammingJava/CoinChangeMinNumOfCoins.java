class Solution {
    public int coinChange(int[] coins, int amount) {
        //dp array in size of total amount
        int[] dp=new int[amount+1];
        Arrays.fill(dp,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
            for(int c:coins)
                //if curr amount greater than curr coin type
                if(i>=c) 
                    //then update the dp value with min of curr dp value and dp[currAmt-currCoin] + 1
                    dp[i]=Math.min(dp[i],dp[i-c]+1);
        //if no combination then return -1
        return dp[amount]>amount?-1:dp[amount];
    }
}
