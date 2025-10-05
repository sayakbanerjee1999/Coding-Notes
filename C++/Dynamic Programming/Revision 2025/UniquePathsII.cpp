class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size();
        int COLS = obstacleGrid[0].size();

        vector<vector<int>> dp(ROWS, vector<int>(COLS, 0));
        // Top Row (All cells have a path of 1 until we hit a obstacle) After obstacle no way of reaching other cells
        for(int i = 0; i < COLS; i++){
            if(obstacleGrid[0][i] == 1)
                break;
            else
                dp[0][i] = 1;
        }

        // Same with 1st col;
        for(int i = 0; i < ROWS; i++){
            if(obstacleGrid[i][0] == 1)
                break;
            else
                dp[i][0] = 1;
        }

        // Now start travsering from (1, 1) to (n-1, m-1)
        // If obstacle set dp[i][j] = 0 (No way of reaching). Else sum of paths
        for(int i = 1; i < ROWS; i++){
            for(int j = 1; j < COLS; j++){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[ROWS-1][COLS-1];
    }
};
