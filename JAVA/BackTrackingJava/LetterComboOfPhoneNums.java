class Solution {
    public List<String> letterCombinations(String digits) {
        //to store our final answers
        ArrayList<String> result = new ArrayList<>();
        
        //check base cases and call dfs function
        if (digits!=null && digits.length()>0){
            //first letter string is mapped to index 2
            String map[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            dfs(digits,map,result,new StringBuilder(),0);
        }
        return result;
    }
    
    public void dfs(String digits, String[] map, ArrayList<String> result, StringBuilder sb, int index){
        //to check where to stop and add to answer; when index reaches the strLen
        if (index==digits.length()){
            result.add(sb.toString());
            return;
        }
        //get the current digits and check what letters it represents
        int digit = Character.getNumericValue(digits.charAt(index));
        String letters = map[digit];
        //add the letter to the string
        for (int i=0;i<letters.length();i++){
            char ch = letters.charAt(i);
            sb.append(ch);
            //take this string and go to next index
            dfs(digits,map,result,sb,index+1);//to call the dfs function recursively with sb and going to the next index in the string digits
            
            //now we apply the concept of backtracking so that we can move back a step and search for other possible combinations 
            sb.deleteCharAt(sb.length()-1);
        }
        
    }
}
