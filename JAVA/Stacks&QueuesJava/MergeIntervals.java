class Solution {
    public class Pair implements Comparable<Pair>{
        int st;
        int et;
        public Pair(int st, int et){
            this.st = st;
            this.et = et;
        }
        //this>other return positive
        //this<other return negative
        //this=other return 0
        public int compareTo(Pair other){
            if (this.st!=other.st)
                //whose start time smaller it will come first in array
                return this.st-other.st;
            else
                return this.et-other.et;
        }
    }
    public int[][] merge(int[][] arr) {
        //for holding the pairs 
        Pair[] pairs = new Pair[arr.length];
        for (int i=0;i<arr.length;i++){
            pairs[i] = new Pair(arr[i][0], arr[i][1]);
        }
        Arrays.sort(pairs);
        Stack<Pair> st = new Stack<>();
        for (int i=0;i<pairs.length;i++){
            if (i==0)
                st.push(pairs[i]);
            else{
                //get the ele on stack top
                Pair top = st.peek();
                if (pairs[i].st>top.et){
                    //if start time greater than end time of top then push
                    st.push(pairs[i]);
                } else{
                    //end time will be max of both
                    top.et = Math.max(top.et, pairs[i].et);
                }
            }
        }
        int[][] ans = new int[st.size()][2];
        for (int i=st.size()-1;i>=0;i--){
            Pair top = st.pop();
            ans[i][0] = top.st;
            ans[i][1] = top.et;
        }
        return ans;
    }
}
