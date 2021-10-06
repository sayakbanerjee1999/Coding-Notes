Maximize Cut Segments - GFG

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;
        
        for(int i = 1; i < n+1; i++){
            // if length >= cut segment i.e., (i-x)>=0 only then possible 
            // also check dp[i-x]!=-1
            if(i-x>=0 && dp[i-x]!=-1)
                dp[i] = max(dp[i], dp[i-x]+1);              //+1 for this cut
            
            if(i-y>=0 && dp[i-y]!=-1)
                dp[i] = max(dp[i], dp[i-y]+1);
                
            if(i-z>=0 && dp[i-z]!=-1)
                dp[i] = max(dp[i], dp[i-z]+1);
        }
        
        return (dp[n]<=0)?0: dp[n];
    }
};
