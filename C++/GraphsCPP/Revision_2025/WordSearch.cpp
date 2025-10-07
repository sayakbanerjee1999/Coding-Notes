class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool dfs(int i, int j, int index, vector<vector<char>>& board, string& word, int n, int m) {
        if (index == word.size())
            return true;

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';          // Change so that cannot be re-used

        for (int dir = 0; dir < 4; dir++) {
            int newX = i + dx[dir];
            int newY = j + dy[dir];
            if (dfs(newX, newY, index + 1, board, word, n, m))
                return true;
        }

        // Backtrack
        board[i][j] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        // Try starting DFS from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {  // match first letter
                    if (dfs(i, j, 0, board, word, n, m))
                        return true;
                }
            }
        }
        return false;
    }
};
