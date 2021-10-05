/*
Given a string, we need to find the minimum number of rotations required to get the same string.

Examples:

Input : s = "geeks"
Output : 5

Input : s = "aaaa"
Output : 1
*/


static int findRotations(String str) 
    { 
        // concatenate string twice. 
        String tmp = str + str; 
        int n = str.length(); 
      
        for (int i = 1; i <= n; i++) 
        { 
      
            // substring from i index of original string size. 
            // in the concatenated string check for the substring starting from index i  
            String substring = tmp.substring(i, i+str.length()); 
      
            // if substring matches with original string then we will break the loop and the index would be our ans. 
            if (str.equals(substring)) 
                return i; 
        } 
        return n; 
    } 
