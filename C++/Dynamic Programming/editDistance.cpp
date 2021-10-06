Edit Distance - GFG

class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int m = s.length();
        int n = t.length();
        
        int dp[m+1][n+1];
        
        for(int i = 0; i < m+1; i++){
            for(int j = 0; j < n+1; j++){
                
                if(i==0)                    // If first string empty, insert all element in 1st string or remove from 2nd string
                    dp[i][j] = j;
                
                else if(j==0)               // Same reason
                    dp[i][j] = i;
                
                else if(s[i-1] == t[j-1])   // IF equal no operation needed move to the next
                    dp[i][j] = dp[i-1][j-1];
                
                else                        // Need one operation and pick minimum from it
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
        
        return dp[m][n];
    }
};
