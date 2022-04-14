LEETCODE - 1337

class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first)
            return a.second < b.second;
        
        return a.first < b.first;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> maxH;
        
        int ind = 0;
        for(auto i: mat){
            int no1s = 0;
            for(int j: i){
                if(j == 1)
                    no1s++;
            }
            
            maxH.push({no1s, ind});
            ind++;
            
            if(maxH.size() > k)
                maxH.pop();
        }
        
        vector<pair<int, int>> res;
        while(!maxH.empty()){
            res.push_back(maxH.top());
            maxH.pop();
        }
        
        sort(res.begin(), res.end(), compare);
        
        vector<int> ans;
        for(int i = 0; i < res.size(); i++)
            ans.push_back(res[i].second);
        
        return ans;
    }
};
