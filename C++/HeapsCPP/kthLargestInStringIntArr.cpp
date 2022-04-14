class Solution {
public:
    class compare{
        public:
        bool operator()(string a, string b){
            if(a.length() != b.length())
                return a.length() > b.length();

            return a > b;
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        
        priority_queue<string, vector<string>, compare> minH;
        for(int i = 0; i < n; i++){
            minH.push(nums[i]);
            
            if(minH.size() > k)
                minH.pop();
        }
        
        return minH.top();
    }
};
