/* Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        //concept is anagrams if sorted are equal
        if (strs == null || strs.length == 0) 
            return new ArrayList<>();
        //keep track of parent string and the anagrams
        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            //convert to char array
            char[] curr = s.toCharArray();
            //sort it
            Arrays.sort(curr);
            //cast it back to string
            String sorted = String.valueOf(curr);
            //if not in map add creating new instance
            if (!map.containsKey(sorted)) 
                map.put(sorted, new ArrayList<>());
            //add to the corresponding list
            map.get(sorted).add(s);
        }
        return new ArrayList<>(map.values());
    }
}
