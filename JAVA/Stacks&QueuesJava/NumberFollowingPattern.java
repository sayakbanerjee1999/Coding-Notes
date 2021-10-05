class Solution{
    static String printMinNumberForPattern(String str){
        // code here
        Stack<Integer> st = new Stack<>();
        String res = "";
        int num = 1;
        for (int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            if (ch=='D'){
                st.push(num);
                num++;
            } else{
                st.push(num);
                num++;
                while(st.size()>0){
                    res+=st.pop();
                }
            }
        }
        st.push(num);
       while(st.size()>0){
            res+=st.pop();
        } 
        return res;
    }
}
