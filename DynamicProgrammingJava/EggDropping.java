class Solution {
    public int superEggDrop(int k, int n) {
        int[][] dp = new int[k+1][n+1];
        for (int i=1;i<=k;i++){
            for (int j=1;j<=n;j++){
                if (i==1){
                    dp[i][j] = j;
                } else if (j==1){
                    dp[i][j] = 1;
                } else{
                    int min = Integer.MAX_VALUE;
                    //so now prev row pointer will traverse from 0 to curr col and my curr row pointer will go back from previous to 0
                    for (int curr=j-1, prev=0; curr>=0 ;curr--, prev++){
                        
                        //for curr row egg survives
                        int v1 = dp[i][curr];
                        //for prev row egg breaks
                        int v2 = dp[i-1][prev];
                        int val = Math.max(v1,v2);
                        min = Math.min(val,min);
                            
                    }
                    dp[i][j] = min+1;
                }
            }
        }
        return dp[k][n];
    }
}

//concept correct TLE :(
