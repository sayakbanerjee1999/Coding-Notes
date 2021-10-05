class Solution {
   char[][] matrix;
    int m;
    int n;

    private void dfs(int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == '0') {
            return;
        }

        matrix[x][y] = '0';

        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x, y + 1);
    }

    public int numIslands(char[][] grid) {
        this.matrix = grid;
        m = grid.length;
        n = grid[0].length;
        int counter = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (matrix[x][y] == '1') {
                    counter++;
                    dfs(x, y);
                }
            }
        }

        return counter;
    }
}
