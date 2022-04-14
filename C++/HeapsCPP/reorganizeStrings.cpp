class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> hashmap;
        for(int i = 0; i < s.length(); i++){
            if(hashmap.find(s[i]) == hashmap.end())
                hashmap[s[i]] = 1;
            else
                hashmap[s[i]]++;
        }
        
        // Idea is to place the char with maximum occurence followed with the char with
        // 2nd highest occurence, continuously
        priority_queue<pair<int, char>> maxH;
        for(auto it: hashmap)
            maxH.push({it.second, it.first});
        
        string res = "";
        while(maxH.size() > 1){
            auto a = maxH.top();
            maxH.pop();
            auto b = maxH.top();
            maxH.pop();
            
            res += a.second;
            res += b.second;
            
            int freq1 = a.first - 1;
            int freq2 = b.first - 1;
            
            if(freq1 > 0)
                maxH.push({freq1, a.second});
            
            if(freq2 > 0)
                maxH.push({freq2, b.second});
        }
        
        if(!maxH.empty()){
            auto temp = maxH.top();
            maxH.pop();
            
            if(temp.first > 1)
                return "";
            else
                res += temp.second;
        }
        
        return res;
    }
};
