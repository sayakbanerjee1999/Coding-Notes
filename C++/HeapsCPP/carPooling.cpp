LEETCODE - 1094

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> carPooling;
        
        // {src, 1, capacity};  {dst, 0, capacity}
        // 1 for boarding flag; 0 for deboarding flag
        // deboarding has 0 since first deboard then enter (similar pattern followed by sorting)
        // if destination of a trip and src of another trip is at same point
        // then sorting will will be 0 first then 1
        for(auto i: trips){
            carPooling.push_back({i[1], 1, i[0]});
            carPooling.push_back({i[2], 0, i[0]});
        }
        
        sort(carPooling.begin(), carPooling.end());
        
        for(auto i: carPooling){
            if(i[1] == 1)                   // Boarding Flag; decrease capacity
                capacity -= i[2];
            
            else if(i[1] == 0)
                capacity += i[2];           // Deboarding Flag; increase capacity
            
            if(capacity < 0)
                return false;
        }
        
        return true;
    }
};
