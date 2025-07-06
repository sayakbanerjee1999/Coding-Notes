class Solution {
public:
    void dfsUtil(int i, int j, vector<vector<char>>& grid, 
                vector<vector<int>> &visited, int deltaRow[], int deltaCol[]){
        visited[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();

        for(int k = 0; k < 4; k++){
            int row = i + deltaRow[k];
            int col = j + deltaCol[k];

            if(row >= 0 && row < m && col >= 0 && col < n && !visited[row][col] && grid[row][col] == '1'){
                dfsUtil(row, col, grid, visited, deltaRow, deltaCol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};

        int cntIslands = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cntIslands ++;
                    dfsUtil(i, j, grid, visited, deltaRow, deltaCol);
                }
            }
        }

        return cntIslands;
    }
};
