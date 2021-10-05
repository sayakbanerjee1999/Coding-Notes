class Solution {
    public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) 
        return "";
    String prefix = strs[0];
    for (int i = 1; i < strs.length; i++)
        //for the remaining strings while index not found
        while(strs[i].indexOf(prefix) != 0)
            //search in shortened substring from end
            prefix = prefix.substring(0,prefix.length()-1);
    return prefix;
}
}
