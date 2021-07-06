class Solution {
    int count  = 0;
    public int islandPerimeter(int[][] grid) {
        count = 0;
        for(int i = 0 ;i<grid.length ;i++){
            for(int j = 0;j<grid[i].length;j++){
                if(grid[i][j] == 1){
                     dfs(grid,i,j);
                    //break as we got island
                     break;
                }
            }
        }
       return count; 
    }
    
    private void dfs(int[][]grid,int i,int j){
        //ovrflow will also add to count
        if(i<0 || i>=grid.length || j<0 || j>=grid[i].length || grid[i][j] == 0 ){
           count++;
          return;
        }
        //check if already visited
        if(grid[i][j] == -1)return;
        //mark visited
        grid[i][j] = -1;
        //for all the 4 directions
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
}
