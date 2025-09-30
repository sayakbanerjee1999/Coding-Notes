class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;

        for(int i = 2*nums.size()-1; i >= 0; i--){
            while(!st.empty() && nums[i%nums.size()] >= st.top())
                st.pop();
            
            if(i < nums.size())
                res[i] = st.empty()? -1: st.top();
            
            st.push(nums[i%nums.size()]);
        }

        return res;
    }
};
