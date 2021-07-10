class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int mpLeft = 0;            //Max Profit Left
        int buyingPriceLeft = prices[0];               // Buying Price should always be minimum
        vector<int> dpLeft(n, 0);
        
        for(int i = 1; i < n; i++){
            buyingPriceLeft = min(buyingPriceLeft, prices[i]);
            
            mpLeft = prices[i] - buyingPriceLeft;
            
            dpLeft[i] = max(mpLeft, dpLeft[i-1]);
        }
        
        
        int mpRight = 0;            //Maximum Profit Right
        int sellingPriceRight = prices[n-1];            //Selling Price should always be maximum
        vector<int> dpRight(n, 0);
        
        for(int i = n-2; i >= 0; i--){
            sellingPriceRight = max(prices[i], sellingPriceRight);
            
            mpRight = sellingPriceRight - prices[i];
            
            dpRight[i] = max(mpRight, dpRight[i+1]);
        }
        
        
        int overallProfit = 0;
        for(int i = 0; i < n; i++){
            int profitNow = dpLeft[i] + dpRight[i];
            overallProfit = max(overallProfit, profitNow);
        }
        
        return overallProfit;
    }
};
