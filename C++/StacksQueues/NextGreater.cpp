class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        vector<int> res(arr.size());
        
        for(int i = arr.size()-1; i >= 0; i--){
            // Pop from stack till the stack top is smaller than equal to current element
            // Because you want to store only bigger elements in the stack
            while(!st.empty() && arr[i] >= st.top()){
                st.pop();
            }
            
            if(!st.empty()){
                res[i] = st.top();
            }
            else{
                res[i] = -1;
            }
            
            st.push(arr[i]);
        }
        
        return res;
    }
};
