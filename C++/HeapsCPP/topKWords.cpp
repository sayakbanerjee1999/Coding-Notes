class Solution {
public:
    static bool compare(pair<string, int> a, pair<string, int> b){
        if(a.second == b.second)
            return a.first < b.first;
        
        return a.second > b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashmap;
        
        int n = words.size();
        for(int i = 0; i < n; i++){
            if(hashmap.find(words[i]) == hashmap.end())
                hashmap[words[i]] = 1;
            else
                hashmap[words[i]]++;
        }
        
        vector<pair<string, int>> res;
        for(auto it: hashmap)
            res.push_back({it.first, it.second});
        
        sort(res.begin(), res.end(), compare);
        
        vector<string> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(res[i].first);
        }
        
        return ans;
    }
};
