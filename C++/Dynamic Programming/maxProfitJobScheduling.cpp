Max Profit in Job Scheduling - LeetCode 1235
  
class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v(n);
        
        for(int i = 0; i < n; i++)
            v[i] = {startTime[i], endTime[i], profit[i]};
        
        sort(v.begin(), v.end(), comp);
        
        int dp[n];
        
        dp[0] = v[0][2];
        
        for(int i = 1; i < n; i++){
            int inc = v[i][2];
            int last = -1;
            int lo = 0;
            int hi = i-1;
            
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                
                //Start Time is >= end time
                if(v[mid][1]<=v[i][0]){
                    last = mid;
                    lo = mid+1;                 //If mid is smaller then elements less will be smaller
                }
                
                else
                    hi = mid-1;
            }
            
            if(last!=-1)
                inc += dp[last];
            
            int exc = dp[i-1];          //If excluded dp[i] = dp[i-1];
            
            dp[i] = max(inc, exc);      // Take maximum val greedily
        }
        
        return dp[n-1];
    }
};
