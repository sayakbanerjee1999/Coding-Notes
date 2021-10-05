class Solution {
    public int largestRectangleArea(int[] heights) {
        //to store nearest smallest to right
        int[] rb = new int[heights.length];
        Stack<Integer> st = new Stack<Integer>();
        //store the rightmost index
        st.push(heights.length-1);
        //if next smaller element on right not there then heights.length as its smallest element
        rb[heights.length-1] = heights.length;
        for (int i=heights.length-2;i>=0;i--){
            while (st.size()>0 && heights[i]<=heights[st.peek()]){
                st.pop();
            }
            if (st.size()==0){
                rb[i] = heights.length;
            }else{
                rb[i] = st.peek();                
            }
            st.push(i);
        }
        
        
        //to store nearest smallest to left
        int[] lb = new int[heights.length];
        Stack<Integer> St = new Stack<Integer>();
        //store the rightmost index
        St.push(0);
        //if next smaller element on left not there then -1 as its smallest element
        lb[0] = -1;
        for (int i=1;i<heights.length;i++){
            while (St.size()>0 && heights[i]<=heights[St.peek()]){
                St.pop();
            }
            if (St.size()==0){
                lb[i] = -1;
                
            }else{
                lb[i] = St.peek();
            }
            St.push(i);
        }
        
        
        int maxArea = 0;
        for (int i=0;i<heights.length;i++){
            int width = rb[i]-lb[i]-1;
            int area = heights[i]*width;
            maxArea = Math.max(area,maxArea);
        }
        return maxArea;
    }
}
