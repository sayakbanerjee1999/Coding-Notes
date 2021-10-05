class Solution {
public:
    
    // obsp - old bought state profit;   nbsp - new ...
    // ossp - old sold state profit;    nssp - new ... 
    // ocsp - old cool state profit;    ncsp - new ...
    
    int maxProfit(vector<int>& prices) {
        int obsp = -prices[0];
        int ossp = 0;
        int ocsp = 0;
        
        for(int i = 1; i < prices.size(); i++){
            int nbsp = 0;
            int nssp = 0;
            int ncsp = 0;
            
            // Buying is done on Cooldown State
            if(ocsp - prices[i] > obsp){
                nbsp = ocsp - prices[i];
            }else{
                nbsp = obsp;
            }
            
            // Selling is done on Old Bought state profit
            if(obsp + prices[i] > ossp){
                nssp = obsp + prices[i];
            } else {
                nssp = ossp;
            }
            
            // Cooldown is on selling state profit
            if(ossp > ocsp){
                ncsp = ossp;
            } else {
                ncsp = ocsp;
            }
            
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
        
        return ossp;
    }
};
