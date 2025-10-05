class Solution {
// Transpose and then Reverse every row 
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose in place only
        // Traverse the upper diagnoal
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Now reverse every row
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
