/* Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/


class Solution {
	public boolean isInterLeave(String s1,String s2,String s3)
	{
       if(s1.length()+s2.length()!=s3.length())
       return false;
       Boolean dp[][]= new Boolean[s1.length()+1][s2.length()+1];
       return  solve(s1,s2,s3,0,0,dp);
    }
    
     boolean solve(String s1,String s2,String s3,int i,int j, Boolean[][]dp)
     {
           if( i == s1.length() && j == s2.length() )
            return  true;
         
         if(dp[i][j]!=null)
         {
             return dp[i][j];
         }
         
        if(i< s1.length() && s1.charAt(i)==s3.charAt(i+j)) 
        {
           boolean f1= solve(s1,s2,s3,i+1,j,dp);
            dp[i][j] =  f1;
            if(f1==true)
            {
                return true;
            }
        }
       if(j< s2.length() && s2.charAt(j)==s3.charAt(i+j)) 
        {
           boolean f2= solve(s1,s2,s3,i,j+1,dp);
            dp[i][j] = f2;
            if(f2==true)
            {
                return true;
            }    
        }   
       dp[i][j]=false;  
       return dp[i][j];  
     }
}
