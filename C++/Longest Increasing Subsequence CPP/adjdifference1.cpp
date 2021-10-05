int longestSubsequence(int N, int arr[]){
        // code here
        vector<int> dp(N, 1);
        
        dp[0] = 1;
        
        for(int i = 1; i < dp.size(); i++){
            for(int j = 0; j < i; j++){
                if(abs(arr[i]-arr[j]) == 1)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        int oMax = 1;
        for(int i = 0; i < dp.size(); i++)
            oMax = max(oMax, dp[i]);
            
        return oMax;
    }
