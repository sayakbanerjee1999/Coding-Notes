LEETCODE - 455
 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        //Assign the largest cookie to the child whose greed is maximum
        int count = 0;
        int i = g.size()-1;
        int j = s.size()-1;
        
        while(i>=0 && j>=0){
            // If the size can satisfy the greed
            if(s[j] >= g[i]){
                j--;
                i--;
                count++;
            }
            
            // If the maximum size can not satidfy the greed leave the child and go to the next child
            else{
                i--;
            }
        }
        
        return count;
    }
};
