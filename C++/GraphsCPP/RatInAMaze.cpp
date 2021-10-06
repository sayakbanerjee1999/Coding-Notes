Rat in a Maze I - GFG

class Solution{
    public:
    vector<string> res;
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        res.clear();
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return res;
        
        string s = "";
        
        dfs(0, 0, s, n, m, visited);
        
        sort(res.begin(), res.end());
        
        return res;
    }
    
    void dfs(int i, int j, string s, int n, vector<vector<int>> &m, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=n || j>=n)
            return;
        
        if(visited[i][j] || m[i][j]==0)
            return;
        
        if(i==n-1  &&  j==n-1){
            res.push_back(s);
            return;
        }
        
        visited[i][j] = true;
        
        dfs(i+1, j, s + 'D', n, m, visited);
        dfs(i-1, j, s + 'U', n, m, visited);
        dfs(i, j+1, s + 'R', n, m, visited);
        dfs(i, j-1, s + 'L', n, m, visited);
        
        visited[i][j] = false;
    }
};
