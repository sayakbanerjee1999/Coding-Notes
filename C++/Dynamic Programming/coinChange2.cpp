Coin Change II - Minimum number of Coins (GFG)

class Solution{

	public:
	int minCoins(int coins[], int m, int V) 
	{ 
	    // Your code goes here
	    int dp[m+1][V+1];
	    
	    for(int i = 0; i < m+1; i++){
	        for(int j = 0; j < V+1; j++){
	            if(i == 0)
	                dp[i][j] = INT_MAX - 1;
	            if(j == 0)
	                dp[i][j] = 0;
	        }
	    }
	    
	    //2nd Row
	   // for(int j = 1; j < V+1; j++){
	   //     if(coins[0]%j == 0)
	   //         dp[1][j] = coins[0]%j;
	        
	   //     else
	   //         dp[1][j] = INT_MAX - 1;
	   // }
	    
	    for(int i = 1; i < m+1; i++){
	        for(int j = 1; j < V+1; j++){
	            if(coins[i-1] <= j)
	                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);      //+1 <- to keep track of count if included analogous to adding price in Knapsack for profit
	            
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	    int res = dp[m][V];
	    
	    if(res >= INT_MAX - 1)
	        return -1;
	        
	    else
	        return res;
	} 
	  
};
