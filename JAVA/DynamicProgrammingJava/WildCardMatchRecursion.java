class Solution {
    public boolean isMatch(String s, String p) {
        return search(s,p);
    }
    
    public boolean search (String s, String p){
        //if pattern is empty then return if other string empty, if its not empty return false as they anyway dont match
        if (p.isEmpty())
            return s.isEmpty();
        else{
            //first character matches or if it is .
            boolean firstMatch = (!s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.'));
        //second character is asterisk or not-confusing part      
            if (p.length()>=2 && p.charAt(1)=='*'){
                //if asterisk then two conditions
                //first - skip the asterisk hence substring p but string remains intact - 0 reps
                //second - if first char matches then use asterisk to have a repetition of that character - 1+ reps; so we move one position in the string but not in the pattern
                return search(s,p.substring(2)) || (firstMatch && search(s.substring(1),p));
        }else{
            //if second character is not * and first character that we computed above is true then we have to check for the rest of the string
            if (firstMatch){
                return search(s.substring(1), p.substring(1));
            } else{
                //if first chars dont match and also there is no * then return false simply
                return false;
                }
            }
        }
    }
}
