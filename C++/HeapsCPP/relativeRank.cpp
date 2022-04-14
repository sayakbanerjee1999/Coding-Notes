LEETCODE - 506
  
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        
        // Build a Max Heap;
        priority_queue<pair<int, int>> scoreHeap;
        
        for(int i = 0; i < n; i++){
            scoreHeap.push({score[i], i});
        }
        
        int i = 1;
        while(!scoreHeap.empty()){
            if(i==1){
                ans[scoreHeap.top().second] = "Gold Medal";
                scoreHeap.pop();
            }
            
            else if(i==2){
                ans[scoreHeap.top().second] = "Silver Medal";
                scoreHeap.pop();
            }
            
            else if(i==3){
                ans[scoreHeap.top().second] = "Bronze Medal";
                scoreHeap.pop();
            }
            
            else{
                ans[scoreHeap.top().second] = to_string(i);
                scoreHeap.pop();
            }
            
            i++;
        }
        
        return ans;
    }
};
