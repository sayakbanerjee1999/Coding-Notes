class Solution
{
    //Function to find the next greater element for each element of the array.
    public static long[] nextLargerElement(long[] arr, int n)
    { 
        // Your code here
        int idx = 0;
        long[] res = new long[n];
        Stack<Long> st = new Stack<Long>();
        for (int i=n-1;i>=0;i--){
            if (st.size()==0){
                res[idx] = -1;
                idx++;
            }
            else if (st.size()>0 && st.peek()>arr[i]){
                res[idx] = st.peek();
                idx++;
            }
            else if (st.size()>0 && st.peek()<=arr[i]){
                while (st.size()>0 && st.peek()<arr[i]){
                    st.pop();
                }
                if (st.size()==0){
                    res[idx] = -1;
                    idx++;
                } else{
                    res[idx] = st.peek();
                    idx++;
                }
            }
            st.push(arr[i]);
        }
    long[] ans = new long[n];
    int in = 0;
    for(int i=n-1;i>=0;i--){
        ans[in]=res[i];
        in++;
    }
    return ans;
    } 
}
