class Solution
{
    //Function to calculate the span of stocks price for all n days.
    //consecutive smaller or equal before it 
    //if greater before chain breaks
    public static int[] calculateSpan(int price[], int n)
    {
        // Your code here
        int[] span = new int[n];
        Stack<Integer> st = new Stack<>();
        st.push(0);
        span[0] = 1;
        for (int i=1;i<n;i++){
            while (st.size()>0 && price[i]>=price[st.peek()]){
                st.pop();
            }
            if (st.size()==0){
                span[i] = i+1;
            } else{
                span[i] = i-st.peek();
            }
            st.push(i);
        }
        return span;
    }
    
}
