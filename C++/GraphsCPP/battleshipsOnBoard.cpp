class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &board, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=n || j>=m)
            return;
        
        if(visited[i][j] || board[i][j]!='X')
            return;
        
        visited[i][j] = 1;
        dfs(i, j+1, n, m, board, visited);
        dfs(i, j-1, n, m, board, visited);
        dfs(i+1, j, n, m, board, visited);
        dfs(i-1, j, n, m, board, visited);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int countShips = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j]=='X'){
                    dfs(i, j, n, m, board, visited);
                    countShips++;
                }
            }
        }
        
        return countShips;
    }
};
