Flood Fill Algorithm - LeetCode 733
  
class Solution {
public:
    void dfsUtil(int i, int j, int x, int y, vector<vector<int>>& image, vector<vector<int>>& visited,
                int oldColor, int newColor){
        if(i<0 || j<0 || i>=x || j>=y) 
            return;
        
        if(image[i][j]!=oldColor || visited[i][j]==1)
            return;
        
        visited[i][j] = 1;
        image[i][j] = newColor;
        
        dfsUtil(i-1, j, x, y, image, visited, oldColor, newColor);
        dfsUtil(i+1, j, x, y, image, visited, oldColor, newColor);
        dfsUtil(i, j-1, x, y, image, visited, oldColor, newColor);
        dfsUtil(i, j+1, x, y, image, visited, oldColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image.size();
        int y = image[0].size();
        
        vector<vector<int>> visited(x, vector<int>(y, 0));
        int oldColor = image[sr][sc];
        
        dfsUtil(sr, sc, x, y, image, visited, oldColor, newColor);
        
        return image;
    }
};
