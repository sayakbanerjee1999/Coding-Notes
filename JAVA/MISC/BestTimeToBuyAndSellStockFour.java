/*  
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
*/

class Solution {
    public int maxProfit(int k, int[] prices) {        
        if (k >= prices.length / 2) { //if k >= n/2, then you can make maximum number of transactions
            int profit = 0;
            //To avoid TLE
            for (int i = 1; i < prices.length; i++)
                if (prices[i] > prices[i - 1]) 
                    profit += prices[i] - prices[i - 1];
            return profit;
        }
        int[] buy = new int[k + 1], sell = new int[k + 1];
        Arrays.fill(buy, Integer.MIN_VALUE);
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = Math.max(buy[i], sell[i - 1] - price);
                sell[i] = Math.max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
}

 
        
