Minimum Path Sum - LeetCode 64

class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int dp[n][m];
        
        // Solving from last cell to the top cell
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i==n-1 && j==m-1)            //Last cell
                    dp[i][j] = arr[i][j];
                
                else if (i==n-1)                //Last Row  -> Movement only to the right
                    dp[i][j] = dp[i][j+1] + arr[i][j];
                
                else if(j==m-1)                 //Last Col  -> Movement only to the Down
                    dp[i][j] = dp[i+1][j] + arr[i][j];
                
                else                                
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + arr[i][j];
            }
        }
        
        return dp[0][0];
    }
};
