Swim in Rising Water - LEETCODE 778 (HARD)

class Solution {
public:
    void dfsIsOk(int i, int j, int n, int m, int mid, vector<vector<int>>& grid, vector<vector<int>>& visited){
        if(i < 0  ||  j < 0  ||  i >= n  ||  j >= m)
            return;
        
        if(visited[i][j]  ||  grid[i][j] > mid)
            return;
        
        visited[i][j] = 1;
        
        dfsIsOk(i-1, j, n, m, mid, grid, visited);
        dfsIsOk(i+1, j, n, m, mid, grid, visited);
        dfsIsOk(i, j-1, n, m, mid, grid, visited);
        dfsIsOk(i, j+1, n, m, mid, grid, visited);
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int l = 0;
        int r = n*m;
        
        while(l < r){
            int mid = l + (r-l)/2;
            
            vector<vector<int>> visited(n, vector<int>(m, 0));
            
            dfsIsOk(0, 0, n, m, mid, grid, visited);
            
            // If entire matrix can in travelled within mid time then it can be travelled for t > mid
            // We need to minimize time so we need to search in lower time interval;
            if(visited[n-1][m-1])
                r = mid;
            
            else
                l = mid+1;
        }
        
        return r;
    }
};
