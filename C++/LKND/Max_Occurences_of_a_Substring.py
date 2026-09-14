# Intuition
# The key observation is that if a substring of length k (where minSize ≤ k ≤ maxSize) 
# appears n times in the string, then every substring of length minSize within that 
# longer substring will also appear at least n times.

# To understand why, consider a substring of length 5 that appears 3 times. 
# Any substring of length 3 within those 5 characters will also appear at least 3 times 
# (at the same positions where the length-5 substring appears). This means that checking 
# longer substrings is redundant - we'll never find a longer substring that has a 
# higher frequency than the best substring of length minSize.

# Additionally, if a longer substring satisfies the unique character constraint (having at most 
# maxLetters unique characters), then any of its substrings will also satisfy this constraint, 
# since a substring cannot have more unique characters than the string containing it.

# Therefore, instead of checking all possible substring lengths from minSize to maxSize, 
# we can optimize by only checking substrings of exactly length minSize. 
# This significantly reduces the search space while guaranteeing we find the maximum frequency.

# The approach becomes straightforward:
# - Generate all substrings of length minSize
# - For each substring, check if it has at most maxLetters unique characters
# - Count the frequency of valid substrings using a hash table
# - Return the maximum frequency found

class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        """The Solution changes to a simple check of - 
        maximum number of occurences of substring of fixed size minSize in s 
        which has at most maxLetters unique chars"""
        
        res = 0
        substringMap = collections.defaultdict(int)

        for idx in range(len(s) - minSize + 1):
            curr_substring = s[idx: idx+minSize]

            # Number of Unique Characters
            unique_chars = set(curr_substring)
            if len(unique_chars) <= maxLetters:
                substringMap[curr_substring] += 1

                res = max(res, substringMap[curr_substring])
        
        return res
