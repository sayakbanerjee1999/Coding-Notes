class Solution {
    // Simple Application of Djisktra - But here distance always increases 
    // by 1 (constant number). So a PQ is not required (all distances pushed
    // will be same so minH is not required). Queue stores it just as needed. 
    // Since PQ is not involved - Time Complexity (O(E)) -> Edges (n x m)
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If Starting Point / Ending Point != 0 Return -1
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0)
            return -1;
        
        // Handle Special Case
        if(grid[0][0]==0 && n==1 && m==1)
            return 1;

        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        distance[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int dist = it.first;
            int x = it.second.first;
            int y = it.second.second;

            for(int i = -1; i <= 1; i++){
                int row = x + i;
                for(int j = -1; j <= 1; j++){
                    int col = y + j;

                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==0){
                        if(row==n-1 && col==m-1)
                            return dist+1;

                        if(dist + 1 < distance[row][col]){
                            q.push({dist+1, {row, col}});
                            distance[row][col] = 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};
