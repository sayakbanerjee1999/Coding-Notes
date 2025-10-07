class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        visited[0][0] = k;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it[0];
            int y = it[1];
            int time = it[2];
            int obs = it[3];

            if(x == n-1 && y == m-1)
                return time;
            
            for(int z = 0; z < 4; z++){
                int nrow = x + dx[z];
                int ncol = y + dy[z];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int nobs = obs - grid[nrow][ncol];
                    if(nobs >= 0 && nobs >= visited[nrow][ncol]){
                        visited[nrow][ncol] = nobs;
                        q.push({nrow, ncol, time + 1, nobs});
                    }
                }
            }
        }

        return -1;
    }
};
