/*package whatever //do not write package name here */

import java.io.*;

class GFG {
    
    public static void main(String[] args){
        String s = "forgeeksskeegfor";
        //ans should be geeksskeeg
        //for aaaabbaa should be aabbaa
        System.out.println(longestPalin(s));
    }
    
	public static int longestPalin(String s) {
        StringBuilder strRev = new StringBuilder();
        strRev.append(s);
        strRev.reverse();
        return longestCommonSubstr(s,strRev.toString());
        // StringBuilder newtemp = new StringBuilder();
        // newtemp.append(temp);
        // return newtemp.reverse().toString();
        
    }
    public static int longestCommonSubstr(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        int ans = 0;
        if (n==0 || m==0)
            return 0;
        int dp[][]  = new int[n+1][m+1];
        for (int i=0;i<n+1;i++){
            for (int j=0;j<m+1;j++){
                if (i==0||j==0)
                    dp[i][j] = 0;
            }
        }
        for (int i=1;i<n+1;i++){
            for (int j=1;j<m+1;j++){
                if (text1.charAt(i-1)==text2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = Math.max(ans,dp[i][j]);
                }
                
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;        
    }
}
