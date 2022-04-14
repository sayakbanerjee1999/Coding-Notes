LEETCODE - 2073

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        while(tickets[k] != 0){
            for(int i = 0; i < tickets.size(); ){
                if(tickets[i] > 0){
                    time ++;
                    tickets[i] --;
                    i++;
                }
                else if(tickets[i] == 0)
                    i++;

                if(tickets[k] == 0){
                    break;
                }
            }  
        }
        
        return time;
    }
};
