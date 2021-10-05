class Solution {
    public int[] maxSlidingWindow(int[] arr, int k) {
        int[] ans = new int[arr.length-k+1];
        int idx = 0;
        Stack<Integer> st = new Stack<>();
        int[] ngr = new int[arr.length];
      //for storing the nearest to right index
        for (int i=arr.length-2;i>=0;i--){
            //-a+
            while (st.size()>0 && arr[i]>arr[st.peek()]){
                st.pop();
            }
            if (st.size()==0){
                ngr[i] = arr.length;
            } else{
                ngr[i] = st.peek();
            }
            st.push(i);
        }
        int j = 0;
        for (int i=0;i<=arr.length-k;i++){
            if (j<i){
                j=i;
            }
            while (ngr[j]<i+k){
                j = ngr[j];
            }
            ans[idx] = arr[j];
            idx++;
        }
        return ans;
    }
}
