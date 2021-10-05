LEETCODE - 187

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hashmap;
        vector<string> res;
        
        string str = s.substr(0, 10);
        
        hashmap[str]++;
        
        int i = 1, j = 10;
        
        // Maintain window length of 10
        while(j < s.length()){
            str.erase(str.begin());            // You can also use str.erase(str.begin())
            str += s[j];
            
            if(hashmap.find(str) == hashmap.end())
                hashmap[str] = 1;
            else
                hashmap[str]++;
            
            i++; j++;
        }
        
        for(auto it: hashmap){
            if(it.second >= 2)
                res.push_back(it.first);
        }
        
        return res;
    }
};
