class Solution {
    public boolean isMatch(String s, String p) {
        //storage medium for our dp approach
        Map<String, Boolean> memo = new HashMap<>();
        return search(s,p,memo);
    }
    
    public boolean search (String s, String p, Map<String, Boolean> memo){
        //to keep a check on the string n pattern lets store them as a key in our map
        String state = s+"-"+p;
        //check if a solution for the state exists
        if (memo.containsKey(state)){
            //if does return it
            return memo.get(state);
        }
        //intermidiate variable
        boolean currAns = false;
        //if pattern is empty then return if other string empty, if its not empty return false as they anyway dont match
        if (p.isEmpty())
            currAns = s.isEmpty();
        else{
            //first character matches or if it is .
            boolean firstMatch = (!s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.'));
        //second character is asterisk or not-confusing part      
            if (p.length()>=2 && p.charAt(1)=='*'){
                //if asterisk then two conditions
                //first - skip the asterisk hence substring p but string remains intact - 0 reps
                //second - if first char matches then use asterisk to have a repetition of that character - 1+ reps; so we move one position in the string but not in the pattern
                currAns = search(s,p.substring(2),memo) || (firstMatch && search(s.substring(1),p,memo));
        }else{
            //if second character is not * and first character that we computed above is true then we have to check for the rest of the string
            if (firstMatch){
                currAns = search(s.substring(1), p.substring(1),memo);
            } 
          }
        }
        //store in map before returning
        memo.put(state,currAns);
        return currAns;
    }
}
