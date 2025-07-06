class Solution {
public:
    // Similar to Surrounded Regions but done using BFS.
    // Again we find the boundary 1 and all islands that are connected to these boundary ones - we can move out of the grid from there.
    // After entire traversal - if we see that a grid cell with 1 is not visited then we make understand that from cell we cannot leave the grid
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};

        queue<pair<int, int>> q;
        // Only insert those indices that are on the boundaries
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j] == 1){
                        visited[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int row = x + deltaRow[k];
                int col = y + deltaCol[k];

                if(row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && grid[row][col]==1){
                    q.push({row, col});
                    visited[row][col] = true;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1)
                    cnt++;
            }
        }

        return cnt;
    }
};
