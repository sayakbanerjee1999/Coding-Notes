Minimum Subset Sum Difference - GFG

class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    // Your code goes here
	    int range = 0;
	    for(int i = 0; i < n; i++)
	        range += arr[i];
	    
	    bool dp[n+1][range+1];
	    
	    for(int i = 0; i < n+1; i++){
	        for(int j = 0; j < range+1; j++){
	            if(i == 0)
	                dp[i][j] = false;
	            if(j == 0)
	                dp[i][j] = true;
	        }
	    }
	    
	    for(int i = 1; i < n+1; i++){
	        for(int j = 1; j < range+1; j++){
	            if(arr[i-1] <= j)
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            else if(arr[i-1] > j)
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	    int minDiff = INT_MAX;
	    vector<int> vals;
	    
	    for(int j = 0; j <= range/2; j++){
	        if(dp[n][j] == true)
	            vals.push_back(j);
	    }
	    
	    int size = vals.size();
	    for(int i = 0; i < size; i++)
	        minDiff = min(minDiff, range - 2*vals[i]);
	
	    return minDiff;
	} 
};
