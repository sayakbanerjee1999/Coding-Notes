class Solution {
    
    public List<String> find_permutation(String S) {
        // Code here
        List<String> res = new ArrayList<>();
        String ans= "";
        Collections.sort(permute(S,ans,res));
        return res;
    }
    static List<String> permute(String s , String answer, List<String> res)
    {  
        
        if (s.length() == 0)
        {
            res.add(answer);
            return res;
        }
         
        for(int i = 0 ;i < s.length(); i++)
        {
            char ch = s.charAt(i);
            String l = s.substring(0, i);
            String r = s.substring(i + 1);
            String rest = l + r;
            permute(rest, answer + ch, res);
        }
        return res;
    }
}
