class Solution {
public:
    
    // obsp - old bought state profit;   nbsp - new ...
    // ossp - old sold state profit;    nssp - new ... 
    int maxProfit(vector<int>& prices, int fee) {
        int obsp = -prices[0];
        int ossp = 0;
        
        for(int i = 1; i < prices.size(); i++){
            int nbsp = 0;
            int nssp = 0;
            
            // Buying a stock
            if(ossp - prices[i] > obsp){
                nbsp = ossp - prices[i];
            } else {
                nbsp = obsp;
            }
            
            // Selling a stock incurs a transaction fee
            if(obsp + prices[i] - fee > ossp){
                nssp = obsp + prices[i] - fee;
            } else {
                nssp = ossp;
            }
            
            ossp = nssp;
            obsp = nbsp;
        }
        
        return ossp;
    }
};
