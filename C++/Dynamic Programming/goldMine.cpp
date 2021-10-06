Gold Mine Problem - GFG

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> arr){
        // code here
        int dp[n][m];
        
        // Solve Column Wise -> Right most to left most
        for(int j = m-1; j >= 0; j--){
            for(int i = 0; i < n; i++){
                int right = (j==m-1)?0 : dp[i][j+1];                    // Right is 0 for last col cells
                    
                int rightUp = (i==0 || j==m-1)?0 : dp[i-1][j+1];        // Right Up is 0 for last col cells or first row cells
                
                int rightDown = (i==n-1 || j==m-1)?0 : dp[i+1][j+1];    // Right Down is 0 for last col cells or last row cells
                
                dp[i][j] = arr[i][j] + max(right, max(rightUp, rightDown));
            }
        }
        
        int maxGold = dp[0][0];
        for(int i = 1; i < n; i++)
            maxGold = max(maxGold, dp[i][0]);
        
        return maxGold;
    }
};
