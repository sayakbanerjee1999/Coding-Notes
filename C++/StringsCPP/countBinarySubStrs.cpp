LEETCODE - 696

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups(s.length());
        
        int idx = 0;
        
        groups[0] = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] != s[i-1]){
                idx++;
                groups[idx] = 1;
            }
            
            else{
                groups[idx]++;
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= idx; i++){
            ans += min(groups[i], groups[i-1]);
        }
        
        return ans;
    }
};
