class Solution {
private:
    void dfsUtil(int x, int y, int initColor, int color, vector<vector<int>>& visited, vector<vector<int>>& image, int deltaRow[], int deltaCol[]){
        image[x][y] = color;
        visited[x][y] = 1;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < 4; i++){
            int row = x + deltaRow[i];
            int col = y + deltaCol[i];

            if(row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && image[row][col] == initColor){
                dfsUtil(row, col, initColor, color, visited, image, deltaRow, deltaCol);
            } 
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Up, Right, Down, Left
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};
        int initColor = image[sr][sc];
        dfsUtil(sr, sc, initColor, color, visited, image, deltaRow, deltaCol);

        return image;
    }
};
