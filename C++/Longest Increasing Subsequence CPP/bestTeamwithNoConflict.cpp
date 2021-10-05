class Solution {
public:
    
    // When you sort according to age. It transforms to a simple LIS Question
    // If age 1 has score 10 and is included. Age 5 has score 7. LIS is not maintained
    // In this question it is referred to as a conflict
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        vector<pair<int, int>> players;
        
        for(int i = 0; i < n; i++){
            players.push_back({ages[i], scores[i]});
        }
        
        sort(players.begin(), players.end());
        
        int dp[n];
        
        for(int i = 0; i < n; i++){
            dp[i] = players[i].second;
        }
        
        int overAllMax = dp[0];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            
            overAllMax = max(overAllMax, dp[i]);
        }
        
        return overAllMax;
    }
};
