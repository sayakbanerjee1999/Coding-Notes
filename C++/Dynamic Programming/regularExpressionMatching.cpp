Regular Expression Matching - LeetCode 10

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        
        bool dp[n+1][m+1];
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < m+1; j++){
                if(i == 0  &&  j == 0){
                    dp[i][j] = true;
                }
                
                else if(i == 0){
                    dp[i][j] = false;
                }
                
                else if(j == 0){
                    char pc = p[i-1];
                    if(pc == '*'){
                        dp[i][j] = dp[i-2][j];
                    } else {
                        dp[i][j] = false;
                    }
                }
                
                else{
                    char pc = p[i-1];
                    char sc = s[j-1];
                    
                    if(pc == '*'){
                        dp[i][j] = dp[i-2][j];
                        
                        char pcsl = p[i-2];
                        if(pcsl == '.' || pcsl == sc){
                            dp[i][j] = dp[i][j] || dp[i][j-1];
                        }
                    } 
                    
                    else if (pc == '.'){
                        dp[i][j] = dp[i-1][j-1];
                    } 
                    
                    else if(pc == sc){
                        dp[i][j] = dp[i-1][j-1];
                    } 
                    
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};
