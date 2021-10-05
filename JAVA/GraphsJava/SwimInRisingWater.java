/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
*/

class Solution {
    public void dfsCheck(int i, int j, int n, int m, int mid, int[][] grid, boolean[][] visited){
        //base conditions
        if(i < 0  ||  j < 0  ||  i >= n  ||  j >= m)
            return;
        
        //if already visited or greater than val then return
        if(visited[i][j]  ||  grid[i][j] > mid)
            return;
        
        //mark visited for next iter
        visited[i][j] = true;

        //check for all the 4 directions
        dfsCheck(i-1, j, n, m, mid, grid, visited);
        dfsCheck(i+1, j, n, m, mid, grid, visited);
        dfsCheck(i, j-1, n, m, mid, grid, visited);
        dfsCheck(i, j+1, n, m, mid, grid, visited);
    }
    
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        int l = 0;
        int r = n*m;
        
        while(l < r){
            int mid = l + (r-l)/2;
            
            boolean[][] visited = new boolean[n][m];
            
            dfsCheck(0, 0, n, m, mid, grid, visited);
            
            //if last cell can be visited in time mid then it can also be visited for time>mid
            // Need least time so lower the search interval
            if(visited[n-1][m-1])
                //search from left to mid now 
                r = mid;
            
            else
                //else if last cell not visited then need greater time search from mid to r now
                l = mid+1;
        }
        
        return r;
    }
}
