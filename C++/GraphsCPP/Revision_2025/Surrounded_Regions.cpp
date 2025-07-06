class Solution {
private:
    void dfsUtil(int x, int y, vector<vector<int>>& visited, 
                vector<vector<char>>& board, int deltaRow[], int deltaCol[]){
        visited[x][y] = 1;
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < 4; i++){
            int row = x + deltaRow[i];
            int col = y + deltaCol[i];

            if(row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && board[row][col] == 'O')
                dfsUtil(row, col, visited, board, deltaRow, deltaCol);
        }
    }

public:
    // All O's connected with O's in the boundary cannot be converted to X
    // Hence do a DFS from O's at the boundaries and mark visited
    // If after visiting all cells you find any O's are still there and it has not been visited then you can convert it to a X
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};

        // Start DFS from the the boundaries (1st row and last row)
        for(int j = 0; j < m; j++){
            if(!visited[0][j] && board[0][j]=='O')
                dfsUtil(0, j, visited, board, deltaRow, deltaCol);
            
            if(!visited[n-1][j] && board[n-1][j]=='O')
                dfsUtil(n-1, j, visited, board, deltaRow, deltaCol);
        }

        // Start DFS from the the boundaries (1st column and last column)
        for(int i = 0; i < n; i++){
            if(!visited[i][0] && board[i][0]=='O')
                dfsUtil(i, 0, visited, board, deltaRow, deltaCol);
            
            if(!visited[i][m-1] && board[i][m-1]=='O')
                dfsUtil(i, m-1, visited, board, deltaRow, deltaCol);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
    }
};
