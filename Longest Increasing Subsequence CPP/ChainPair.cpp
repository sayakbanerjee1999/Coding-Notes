class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int, int>> v;
        for(auto i: pairs){
            v.push_back({i[0], i[1]});
        }
        
        int n = v.size();
        
        sort(v.begin(), v.end());
        
        vector<int> dp(n, 1);
        
        dp[0] = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(v[j].second < v[i].first)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        int oMax = 1;
        for(int i = 0; i < n; i++)
            oMax = max(oMax, dp[i]);
        
        return oMax;
    }
};
