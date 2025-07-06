class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2 && visited[i][j]==0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }

        int deltarow[] = {-1, 0, +1, 0};
        int deltacol[] = {0, +1, 0, -1};
        int time = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(t, time);
            for(int i = 0; i < 4; i++){
                int row = x + deltarow[i];
                int col = y + deltacol[i];

                if(row >= 0 && row < n && col >= 0 && col < m && visited[row][col]!=2 && grid[row][col] == 1){
                    q.push({{row, col}, time+1});
                    visited[row][col] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time;
    }
};
