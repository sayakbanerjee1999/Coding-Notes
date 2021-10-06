Longest Palindromic Subsequence - LeetCode 516

class Solution {
public:
    int LCS(string a, string b, int n){
        int dp[n+1][n+1];
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < n+1; j++){
                if(i == 0  ||  j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
    
    string reverseString(string s){
        reverse(s.begin(), s.end());
        
        return s;
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string a = reverseString(s);
        
        return LCS(s, a, n);
    }
};
