class Solution {
    public int maxProfit(int[] prices, int fee) {
        int sell = 0;
        //buying the first stock which will yield negative balance so...
        int buy = -prices[0];
        //then for others traverse
        for (int i=1;i<prices.length;i++){
            //either we can sell a stock or do nothing
            //for selling we have to add the last buying prices to current price - transFee
            sell = Math.max(sell, buy+prices[i]-fee);
            //we can buy or skip in a day
            //if we want to buy then subtract today's price from sell
            buy = Math.max(buy, sell-prices[i]);
        }
        return sell;
    }
}
