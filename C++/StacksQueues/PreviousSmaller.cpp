class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> res(arr.size());
        
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[i] <= st.top())
                st.pop();
            
            res[i] = st.empty()? -1: st.top();
            st.push(arr[i]);
        }
        
        return res;
    }
};
