LEETCODE - 79
  
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i, j, n, m, board, 0, word))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int i, int j, int n, int m, vector<vector<char>>& board, int pos, string word){
        if(i < 0  ||  j < 0  ||  i >= n  ||  j >= m || board[i][j] != word[pos])
            return false;
        
        if(pos == word.length()-1)
            return true;
        
        char temp = board[i][j];
        board[i][j] = '-';
        
        bool check = dfs(i+1, j, n, m, board, pos+1, word)
                    || dfs(i-1, j, n, m, board, pos+1, word)
                    || dfs(i, j+1, n, m, board, pos+1, word)
                    || dfs(i, j-1, n, m, board, pos+1, word);
        
        board[i][j] = temp;
        
        return check;
    }
};
