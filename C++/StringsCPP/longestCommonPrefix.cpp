class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        
        string check = strs[0];
        
        // Compare letter by letter of first word
        for(int i = 0; i < check.length(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != check[i])
                    return lcp;            
            }
            
            lcp += check[i];
        }
        
        return lcp;
    }
};
