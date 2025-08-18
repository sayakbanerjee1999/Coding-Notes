class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # https://www.youtube.com/watch?v=xtqN4qlgr8s&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=7
        dict_ = {"a": -1, "b": -1, "c": -1}
        count = 0

        for i in range(len(s)):
            dict_[s[i]] = i

            # If none of the a, b, c values are -1 seems have seen all chars. 
            # Now to find the count of substrings -> Find the min Index. Everything to the left is also a valid substring. 
            # So if minIndex is 1. Valid substrings will start from [0:], [1:]. Hence minIndex+1
            if dict_["a"] != -1 and dict_["b"] != -1 and dict_["c"] != -1:
                minIndex = min(dict_.values())
                count += (minIndex + 1)
        
        return count
