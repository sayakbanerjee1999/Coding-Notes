class Solution {
public:
    int count = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        
        // Overflows or side is water then also perimeter increases by 1
        if(i < 0  ||  j < 0  ||  i >= n  ||  j >=m  ||  grid[i][j]==0){
            count++;
            return;
        }
        
        if(visited[i][j])
            return;
        
        visited[i][j] = true;
        
        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        count = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j]  &&  grid[i][j] == 1){
                    dfs(grid, i, j, visited);
                    
                    //Only one island is present as stated in question hence break
                    break;
                }
            }
        }
        
        return count;
    }
};
