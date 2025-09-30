class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++){
            // If positive just push
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            } 
            // Handle negative cases
            else {
                // If asteroids size greater than top keep popping till it encounters bigger asteroid
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top())
                    st.pop();
                
                // If same size pop the the top of the stack
                if(!st.empty() && abs(asteroids[i]) == st.top())
                    st.pop();
                // Only push -ve asteroids if stack is empty or stack top is -ve
                else if(st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
            }
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
