Count Number of Islands - LeetCode 200
  
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int countIslands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    countIslands++;
                    dfs(i, j, n, m, visited, grid);
                }
            }
        }
        
        return countIslands;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<char>>& grid){
        if(i<0 || i>=n || j<0 || j>=m)
            return;
        
        if(visited[i][j] || grid[i][j]!='1')
            return;
        
        visited[i][j] = true;
        
        dfs(i+1, j, n, m, visited, grid);
        dfs(i-1, j, n, m, visited, grid);
        dfs(i, j+1, n, m, visited, grid);
        dfs(i, j-1, n, m, visited, grid);
    }
};
