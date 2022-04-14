class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxH;
        vector<int> res;
        
        for(int i = 0; i < arr.size(); i++){
            maxH.push({abs(arr[i] - x), arr[i]});
            
            if(maxH.size() > k)
                maxH.pop();
        }
        
        while(!maxH.empty()){
            res.push_back(maxH.top().second);
            maxH.pop();
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};
