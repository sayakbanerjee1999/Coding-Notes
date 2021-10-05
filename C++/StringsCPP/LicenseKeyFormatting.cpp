LEETCODE - 482
  
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        
        int i = s.length() - 1;
        int count = 0;
        
        while(i >= 0){
            char chr = toupper(s[i]);
            
            if(chr == '-'){
                i--;
            }
            
            else if(count == k){
                res += '-';
                count = 0;
            }
            
            else{
                res += chr;
                count++;
                i--;
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
