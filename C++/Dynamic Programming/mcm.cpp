Matrix Chain Multiplication - GFG

class Solution{
public:
    
    int dp[101][101];
    
    int solve(int arr[], int i, int j){
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int mn = INT_MAX;
        for(int k = i; k < j; k++){
            int tempAns = solve(arr, i, k) + solve(arr, k+1, j) 
                          + (arr[i-1]*arr[k]*arr[j]);
            
            if(tempAns < mn)
                mn = tempAns;
        }
        
        return dp[i][j] = mn;
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        
        int i = 1, j = n-1;
        
        return solve(arr, i, j);
    }
};
