LEETCODE - 1326

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min = 0;
        int max = 0;
        int open = 0;
        
        while(max < n){
            for(int i = 0; i <= n; i++){
                if((i - ranges[i]) <= min  &&  (i + ranges[i]) > max){
                    max = i + ranges[i];
                }
            }
            
            if(min == max)
                return -1;
            
            open++;
            
            min = max;
        }
        
        return open;
    }
};
