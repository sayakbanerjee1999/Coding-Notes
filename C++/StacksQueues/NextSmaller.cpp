class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> res(arr.size());
        
        for(int i = arr.size()-1; i >= 0; i--){
            // Pop from stack till the stack top greater than equal to current element
            // Because you want to store smaller elements in your stack
            while(!st.empty() && arr[i] <= st.top())
                st.pop();
            
            res[i] = st.empty() ? -1: st.top();
            st.push(arr[i]);
        }
        
        return res;
    }
};
