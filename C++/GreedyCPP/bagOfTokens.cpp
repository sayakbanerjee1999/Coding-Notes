LEETCODE - 948
  
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int maxPoints = 0;
        int points = 0;
        
        int i = 0, j = tokens.size()-1;
        
        while(i <= j){
            if(power >= tokens[i]){
                points ++;
                power -= tokens[i];
                i++;
                maxPoints = max(maxPoints, points);
            }
            
            // You can choose face down only if you have at least 1 point
            else if(points > 0){
                points--;
                power += tokens[j];
                j--;
            } 
            
            // If nothing can be done return 
            else{
                return maxPoints;
            }
        }
        
        return maxPoints;
    }
};
