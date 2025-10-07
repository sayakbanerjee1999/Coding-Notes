// This code boils down to distance of 0 from nearest 1
class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] and grid[i][j]==1){
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        // Edge Case if all 0's
        if(q.empty())
            return -1;

        int maxi = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int dist = it.second;

            maxi = max(dist, maxi);
            for(int k = 0; k < 4; k++){
                int nrow = x + dx[k];
                int ncol = y + dy[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==0){
                    q.push({{nrow, ncol}, dist+1});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        // Edge Case (If all 1s)
        return maxi==0 ? -1: maxi;
    }
};
