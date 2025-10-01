class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            // Maintain monotonically increasing stack. Whenever smaller value encounter -> This is the NSE of the current top. 
            // Start popping from the stack till you find an element smaller than the current (about to be pushed).
            // PSE of the top element is either the previous element or -1(if stack empty).
            // While popping calculate the area of this particular element with the nse and pse.
            while(!st.empty() && heights[i] < heights[st.top()]){
                int ele = st.top();
                st.pop();
                int nse = i;
                // Pop first so that the top now is the pse
                int pse = st.empty()? -1: st.top();
                int area = heights[ele] * (nse-pse-1);
                maxArea = max(area, maxArea);
            }

            st.push(i);
        }

        // Left over in the stack
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            int nse = heights.size();
            int pse = st.empty()? -1: st.top();
            int area = heights[ele]*(nse-pse-1);
            maxArea = max(maxArea, area);
        }    

        return maxArea;
    }
};
