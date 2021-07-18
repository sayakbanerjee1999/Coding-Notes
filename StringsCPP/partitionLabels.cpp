LEETCODE - 763

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        
        // Record the last occuring index of every character in the string 
        int lastIndex[26];
        for(int i = 0; i < s.length(); i++){
            lastIndex[s[i] - 'a'] = i; 
        }
        
        int i = 0;
        while(i < s.length()){
            int end = lastIndex[s[i] - 'a'];
            int j = i;
            
            while(j != end){
                end = max(end, lastIndex[s[j] - 'a']);
                j++;
            }
            
            res.push_back(end-i+1);                 //res.push_back(j-i+1)
            i = j+1;
        }
        
        return res;
    }
};
