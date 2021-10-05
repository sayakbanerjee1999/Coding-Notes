class Solution {
    
    public int minDis(String s1, String s2, int n, int m, int[][]dp){
          // If any String is empty,
      // return the remaining characters of other String
      
      if(n == 0)    
        return m;  
      if(m == 0)    
        return n;
                 
      // To check if given n & m has already been executed
      if(dp[n][m] != -1)    
        return dp[n][m];
                
      // If characters are equal, execute recursive function for n-1, m-1
      if(s1.charAt(n-1) == s2.charAt(m-1))
      {           
        if(dp[n-1][m-1] == -1)
        {               
          return dp[n][m] = minDis(s1, s2, n-1, m-1, dp);           
        }        
        else
          return dp[n][m] = dp[n-1][m-1];   
      }
  
    //If characters are not equal, we need to
    //Find the minimum cost out of all 3 operations.      
      else
      {           
        int m1, m2, m3;        // temp variables   
        if(dp[n-1][m] != -1)
        {    
          m1 = dp[n - 1][m];      
        }           
        else
        {   
          m1 = minDis(s1, s2, n - 1, m, dp);      
        }            
                
        if(dp[n][m - 1] != -1)
        {                
          m2 = dp[n][m - 1];            
        }            
        else
        {    
          m2 = minDis(s1, s2, n, m - 1, dp);      
        }                                   
       
        if(dp[n - 1][m - 1] != -1)
        {    
          m3 = dp[n - 1][m - 1];      
        }   
        else
        {   
          m3 = minDis(s1, s2, n - 1, m - 1, dp);       
        }     
        return dp[n][m] = 1 + Math.min(m1, Math.min(m2, m3));        
      }             
    }
    
    public int editDistance(String s1, String s2) {
        // Code here
        int n = s1.length();
      int m = s2.length();
      int[][] dp = new int[n+1][m+1];
      for(int i = 0; i < n + 1; i++)
        Arrays.fill(dp[i], -1);    
       return minDis(s1,s2,n,m,dp);
    }
}
