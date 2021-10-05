/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 
 */

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length()+1];
        
        //base case; empty string into valid words
        dp[0] = true;
        
        for (int i=0;i<=s.length();i++){
            //at each position look at all possible substrings that end in i
            for (int j=0;j<i;j++){
                //if substring bw j and i are valid
                //and if everything before j can be validly split
                if (dp[j] && wordDict.contains(s.substring(j,i))){
                    dp[i] = true;
                    break; // no need to keep looking if we find one valid
                }
            }
        }
        return dp[s.length()];
    }
}


