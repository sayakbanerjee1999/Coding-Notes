Maximum Sum Rectangle in 2D Matrix - GFG

class Solution {
  public:
    int kadane(vector<int> arr, int size){
        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        
        for(int i = 0; i < size; i++){
            max_ending_here += arr[i];
            
            max_so_far = max(max_so_far, max_ending_here);
            
            if(max_ending_here < 0)
                max_ending_here = 0;
        }
        
        return max_so_far;
    }
    
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int maximumSum = INT_MIN;
        
        for(int i = 0; i < R; i++){
            vector<int> v(C, 0);
            
            //to explore all possible rectangles
            for(int j = i; j < R; j++){
                for(int k = 0; k < C; k++){
                    v[k] += M[j][k]; 
                }
                
                maximumSum = max(maximumSum, kadane(v, C));
            }
        }
        
        return maximumSum;
    }
};
