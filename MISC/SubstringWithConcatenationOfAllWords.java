/*
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
*/


public class Solution{
public List<Integer> findSubstring(String s, String[] words) {
    //first the base condition
        if (s == null || words == null || s.length() == 0 || words.length == 0) {
            return new ArrayList<>();
        }
    //to keep the words in words[] and their frequency
        Map<String, Integer> counts = new HashMap<>();
        for (String word : words) {
            counts.put(word, counts.getOrDefault(word, 0) + 1);
        }
        
        List<Integer> r = new ArrayList<>();
    //length of the string
        int sLen = s.length();
    //total number of words
        int num = words.length;
    //length of each word
        int wordLen = words[0].length();

    //it will run till total len - (number of words*wordlength)+1
        for (int i=0; i<sLen-num*wordLen + 1; i++) {
            //all combos of all the words in any order so it should search till i+num*wordlen
            String sub = s.substring(i, i + num*wordLen);
            //check the concat function result
            if (isConcat(sub, counts, wordLen)) {
                //add the index of occurrence
                r.add(i);
            }
        }
        return r;
    }
    
    //so here we check if a valid combo is found
    private boolean isConcat(String sub, Map<String, Integer> counts, int wordLen) {
        Map<String, Integer> seen = new HashMap<>();
        //run till the substring length incrementing by each word length every iteration
        for (int i = 0; i < sub.length(); i += wordLen) {
            //check for the substring presence and add to hm
            String sWord = sub.substring(i, i + wordLen);
            seen.put(sWord, seen.getOrDefault(sWord, 0) + 1);
        }
        //check if bth maps are equal then return true
        return seen.equals(counts);
    }
}
