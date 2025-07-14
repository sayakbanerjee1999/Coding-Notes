class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>>> minH;

        effort[0][0] = 0;
        minH.push({0, {0, 0}});

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};

        while(!minH.empty()){
            auto it = minH.top();
            minH.pop();

            int eff = it.first;
            int x = it.second.first;
            int y = it.second.second;

            // Minimum will always be at the top - No way you can get anything less
            if(x==n-1 && y==m-1)
                return eff;
            
            for(int i = 0; i < 4; i++){
                int row = x + deltaRow[i];
                int col = y + deltaCol[i];

                if(row>=0 && row<n && col>=0 && col<m){
                    int newEffort = max(abs(heights[row][col]-heights[x][y]), eff);
                    if(newEffort < effort[row][col]){
                        effort[row][col] = newEffort;
                        minH.push({newEffort, {row, col}});
                    }    
                }
            }
        }

        // return effort[n-1][m-1]; If you do not return from the top
        return 0;
    }
};
