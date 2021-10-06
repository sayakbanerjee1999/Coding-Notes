Dungeon Game - LeetCode 174

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        int dp[n][m];
        
        // if arr[i][j] + dp[i][j+1]/dp[i+1][j] > 0 then from that position 
        // knight can always save the princess as we he gets a power up.
        // So if it's > 0 set as 0. as with that energy + 1, and getting a power up 
        // on entering the cell the knight can reach the princess easily.
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i==(n-1) && j==(m-1))                //Last row
                    dp[i][j] = min(0, dungeon[i][j]);
                
                else if(i==(n-1))                       //Movement only right
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j+1]);
                
                else if(j==(m-1))                       //Movement only down
                    dp[i][j] = min(0, dungeon[i][j] + dp[i+1][j]);
                
                else
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i+1][j], dp[i][j+1]));
            }
        }
        
        return abs(dp[0][0])+1;
    }
};
