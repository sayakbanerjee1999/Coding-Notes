LEETCODE 1293 - Shortest Path in a Grid with Obstacles Elimination

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Visited array stores the k left at that cell
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        // queue format -> {i, j, length, k_left}
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int x = temp[0], y = temp[1];
            
            // Search within bounds
            if(x<0 || x>=m || y<0 || y>=n)
                continue;
            
            // If dst is reached; 
            if(x == m-1  &&  y == n-1)
                return temp[2];
            
            // If you hit a obstacle
            if(grid[x][y] == 1){
                if(temp[3] > 0)
                    temp[3]--;
                else
                    continue;
            }
            
            // Check visited array
            if(visited[x][y] != -1  &&  visited[x][y] >= temp[3]){
                continue;
            }
            
            visited[x][y] = temp[3];
            
            q.push({x+1, y, temp[2] + 1, temp[3]});
            q.push({x-1, y, temp[2] + 1, temp[3]});
            q.push({x, y+1, temp[2] + 1, temp[3]});
            q.push({x, y-1, temp[2] + 1, temp[3]});
        }
        
        return -1;
    }
};
