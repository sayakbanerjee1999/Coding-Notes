// User function Template for C++

class Solution {
  // Idea is to find coordinates in the same order and push to set. If same we will have unique counts. Hence baseX, baseY is subtracted to keep the points normalized
  public:
    void dfsUtil(int x, int y, vector<pair<int, int>> &vec, 
                vector<vector<int>>& visited, vector<vector<int>>& grid, 
                int deltaRow[], int deltaCol[], int baseX, int baseY){
        int n = grid.size();
        int m = grid[0].size();         
        visited[x][y] = 1;
        vec.push_back({x-baseX, y-baseY});
        
        for(int i = 0; i < 4; i++){
            int row = x + deltaRow[i];
            int col = y + deltaCol[i];
            
            if(row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] 
            && grid[row][col]==1)
                dfsUtil(row, col, vec, visited, grid, deltaRow, deltaCol, baseX, baseY);
        }
                    
    }
                
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};
        
        set<vector<pair<int, int>>> res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int, int>> vec;
                    dfsUtil(i, j, vec, visited, grid, deltaRow, deltaCol, i, j);
                    res.insert(vec);
                }
            }
        }
        
        return res.size();
    }
};
