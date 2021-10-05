class Solution {
    public int longestPalindromeSubseq(String s) {
        StringBuilder strRev = new StringBuilder();
        strRev.append(s);
        strRev.reverse();
        return longestCommonSubsequence(s,strRev.toString());
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        if (n==0 || m==0)
            return 0;
        int dp[][]  = new int[n+1][m+1];
        for (int i=1;i<n+1;i++){
            for (int j=1;j<m+1;j++){
                if (text1.charAt(i-1)==text2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];        
    }
}
