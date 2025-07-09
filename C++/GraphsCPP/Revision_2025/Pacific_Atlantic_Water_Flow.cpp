class Solution {
    // For Atlantic all edges can flow into it. Start DFS and find all connecting edge that can >= height of the edge (such edges can also flow through to Atlantic)
    // Similar for Pacific.
    // Finally, find the intersection of all indices for both
private:
    int deltaRow[4] = {-1, 0, +1, 0};
    int deltaCol[4] = {0, +1, 0, -1};

    void dfsUtil(int x, int y, vector<vector<int>>& heights, 
                vector<vector<int>>& visited, vector<vector<int>>& ocean){
        visited[x][y] = 1;
        ocean.push_back({x, y});

        int n = heights.size();
        int m = heights[0].size();

        for(int i = 0; i < 4; i++){
            int row = x + deltaRow[i];
            int col = y + deltaCol[i];

            if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && heights[row][col]>=heights[x][y])
                dfsUtil(row, col, heights, visited, ocean);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> visitedA(n, vector<int>(m, 0));
        vector<vector<int>> visitedP(n, vector<int>(m, 0));
        vector<vector<int>> pacific;
        vector<vector<int>> atlantic;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // Atlantic
                if(j==m-1 || i==n-1){
                    if(!visitedA[i][j])
                        dfsUtil(i, j, heights, visitedA, atlantic);
                }

                // Pacific
                if(i==0 || j==0){
                    if(!visitedP[i][j])
                        dfsUtil(i, j, heights, visitedP, pacific);
                }
            }
        }

        sort(pacific.begin(), pacific.end());
        sort(atlantic.begin(), atlantic.end());

        vector<vector<int>> res;
        set_intersection(pacific.begin(), pacific.end(), atlantic.begin(), atlantic.end(), inserter(res, res.begin()));
        
        return res;
    }
};
