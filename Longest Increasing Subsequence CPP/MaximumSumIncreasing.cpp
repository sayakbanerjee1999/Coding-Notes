int maxSumIS(int arr[], int n)  {  
	    // Your code goes here
	    int dp[n];
	    
	    for(int i = 0; i < n; i++){
	        int maximum = -1;
	        for(int j = 0; j < i; j++){
	            if(arr[j] < arr[i]){
	                if(maximum == -1){
	                    maximum = dp[j];
	                } else if (dp[j] > maximum){
	                    maximum = dp[j];
	                }
	            }
	        }
	        
	        if(maximum == -1){
	            dp[i] = arr[i];
	        } else {
	            dp[i] = arr[i] + maximum;
	        }
	    }
	    
	    int overallMax = INT_MIN;
	    for(int i = 0; i < n; i++){
	        overallMax = max(overallMax, dp[i]);
	    }
	    
	    return overallMax;
	}
