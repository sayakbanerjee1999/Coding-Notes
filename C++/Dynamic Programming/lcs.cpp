Longest Commmon Subseqence - LeetCode 1143
 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        int arr[m + 1][n + 1];
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i==0 || j==0)
                    arr[i][j] = 0;
                
                else if(text1[i-1] == text2[j-1])
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                
                else
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
        
        return arr[m][n];
    }
};
