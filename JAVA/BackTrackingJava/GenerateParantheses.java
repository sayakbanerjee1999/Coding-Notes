class Solution {
    ArrayList<String> ans = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        String str = "";
        
        parenthesis(0, 0, n, str);
        return ans;
    }
    
    private void parenthesis(int open, int close, int n , String str){
        if(open == n && close == n){
            ans.add(str);
        }
        
        if(open == n + 1 && close != n + 1)
            return;
        
        parenthesis(open + 1, close, n, str + "(");
        if(open > close)
            parenthesis(open, close + 1, n, str + ")");
    }
}
