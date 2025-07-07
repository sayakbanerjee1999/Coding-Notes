class Solution {
    // Always use multi-source BFS and start with number from which you need to find the nearest cell.
    // So for example, if you need to find the distance of every cell from nearest 1 - you push every 1 in the matrix to the 
    // visited matrix with a step of 0 (nearest 1 is itseld). Similarly if you need to find the distance of every cell from nearest 0 - you 
    // push every 0 to the visited matrix with a step 0
    // Remember distance of a cell to the nearest 0 is equivalent to the distance between the nearest 0 and the cell (approach applied here)
    // Then apply bfs to all cells that are not 0's to find the minimum distance.
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int step = q.front().second;
            q.pop();

            dist[x][y] = step;
            for(int k = 0; k < 4; k++){
                int row = x + deltaRow[k];
                int col = y + deltaCol[k];

                if(row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && mat[row][col]==1){
                    visited[row][col] = 1;
                    q.push({{row, col}, step+1});
                }
            }
        }

        return dist;
    }
};
