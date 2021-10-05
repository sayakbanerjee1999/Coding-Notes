/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
*/


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
