Optimal Strategy for a Game - GFG


int dp[1001][1001];

long long solve(int arr[], int i, int j){
    if(i>j)
        return 0;
    
    //Memoization
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    // If I take i; Opponent has to take (i+1->j);
    // Opponent will try to take a val that makes the option for me minimum
    // If opponent takes i+1 -> I have a choice between (i+2)->j
    // If opponent takes j -> I have a choice between (i+1)->(j-1)
    int val1 = arr[i] + min(solve(arr, i+2, j), solve(arr, i+1, j-1));
    
    // If I take j; Opponent has to take (i->j-1);
    // Opponent will try to take a val that makes the option for me minimum
    // If opponent takes i -> I have a choice between (i+1)->(j-1)
    // If opponent takes j-1 -> I have a choice between (i)->(j-2)
    int val2 = arr[j] + min(solve(arr, i, j-2), solve(arr, i+1, j-1));
    
    return dp[i][j] = max(val1, val2);
} 

long long maximumAmount(int arr[], int n) {
    // Your code here
    dp[n][n];
    
    memset(dp, -1, sizeof(dp));
    
    return solve(arr, 0, n-1);
}
