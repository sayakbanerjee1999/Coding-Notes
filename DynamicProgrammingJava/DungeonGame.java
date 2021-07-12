public class Solution {
public int calculateMinimumHP(int[][] grid) {
    int m = grid.length;
    int n = grid[0].length;
    int[][] dp = new int[m][n];
    dp[m-1][n-1] = Math.max(1 - grid[m-1][n-1], 1);
    //fill out the last row
    for(int j = n-2; j >= 0; j--) {
        dp[m-1][j] = Math.max(dp[m-1][j+1] - grid[m-1][j], 1);
    }
    //fill out the last column
    for(int i = m-2; i >= 0; i--) {
        dp[i][n-1] = Math.max(dp[i+1][n-1] - grid[i][n-1], 1);
    }
    //fill out the rest of the dp
    for(int i = m-2; i >= 0; i--) {
        for(int j = n-2; j >= 0; j--) {
            int next = Math.min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = Math.max(next - grid[i][j], 1);
        }
    }
    return dp[0][0];
}
}
