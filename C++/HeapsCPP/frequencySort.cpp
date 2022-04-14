class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashmap;
        
        for(int i = 0; i < s.length(); i++){
            if(hashmap.find(s[i]) == hashmap.end())
                hashmap[s[i]] = 1;
            else
                hashmap[s[i]]++;
        }
        
        priority_queue<pair<int, char>> maxH;
        for(auto it: hashmap){
            maxH.push({it.second, it.first});
        }
        
        string res = "";
        while(!maxH.empty()){
            auto temp = maxH.top();
            maxH.pop();
            
            for(int i = 0; i < temp.first; i++){
                res += temp.second;
            }
        }
        
        return res;
    }
};
