class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        
        priority_queue<pair<int, pair<int, int>>> maxH;
        for(auto i: points){
            maxH.push({i[0]*i[0] + i[1]*i[1], {i[0], i[1]}});
            
            if(maxH.size() > k)
                maxH.pop();
        }
        
        while(!maxH.empty()){
            auto temp = maxH.top();
            maxH.pop();
            
            // vector<int> pts = {temp.second.first, temp.second.second};
            res.push_back({temp.second.first, temp.second.second});
        }
        
        return res;
    }
};
