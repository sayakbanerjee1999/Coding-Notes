class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        
        for(int i = 0; i < stones.size(); i++){
            maxH.push(stones[i]);
        }
        
        while(maxH.size() > 1){
            int a = maxH.top();
            maxH.pop();
            int b = maxH.top();
            maxH.pop();
            
            if(a != b)
                maxH.push(abs(a-b));
            else
                maxH.push(0);
        }
        
        return maxH.top();
    }
};
