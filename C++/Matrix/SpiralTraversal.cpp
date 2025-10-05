class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0;
        int left = 0;
        int bottom = ROWS-1;
        int right = COLS-1;

        vector<int> res;
        while(left<=right && top<=bottom){
            // Traverse left to right, Top(row) fixed
            // After that inrease top by 1 (below row)
            for(int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            top++;

            // Traverse top to bottom, right(col) fixed
            // After that decrease row by 1 
            if(left<=right){
                for(int i = top; i <= bottom; i++)
                    res.push_back(matrix[i][right]);
                right--;
            }

            // Traverse right to left, bottom(row) fixed
            // After that decrease bottom by 1
            if(bottom>=top){
                for(int i = right; i >= left; i--)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Traverse bottom to top, left(col) fixed
            // After that increase left by 1
            if(left <= right){
                for(int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }

        return res;
    }
};
