Maximum Size Square Submatrix with all 1

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int dp[n][m];
        int ans = 0;
        
        if(n==1){
            for(int j = 0; j < m; j++)
                ans = max(ans, mat[n-1][j]);
        }
        
        else if(m==1){
            for(int i = 0; i < n; i++)
                ans = max(ans, mat[i][m-1]);
        }
    
        // Solve from rightmost bottom to top
        else {
            for(int i = n-1; i >= 0; i--){
                for(int j = m-1; j >= 0; j--){
                    if(i==n-1 && j==m-1)
                        dp[i][j] = mat[i][j];
                    else if(i==n-1)
                        dp[i][j] = mat[i][j];
                    else if (j==m-1)
                        dp[i][j] = mat[i][j];
                    else{
                        if(mat[i][j] == 0)
                            dp[i][j] = 0;
                        else
                            dp[i][j] = min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1])) + 1;
                            
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }
        
        return ans;
    }
};
