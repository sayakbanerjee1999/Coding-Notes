# We are following the folloing encoding procesdure
# (lengthStr)(delimiter)(string)(lengthStrNext)(delimiter)(nextString)
# ["leet", "code"]
# 4$leet4$code
# ["leet$", "$code"]
# 5$leet$5$$code
# However since we know length then delimiter -> decoding is very easy

class Solution:
    def encode(self, s):
        # code here
        res = ""
        for word in s:
            res += str(len(word)) + "$" + word
        
        return res

    def decode(self, s):
        # code here
        res = []
        l = 0
        
        # we know the first few characters before we encounter $ would an integer signifyin the length of the first word
        while l < len(s):
            j = l
            # While is important because the word can be arbitrarily long
            while s[j] != "$":
                j += 1
            
            length = int(s[l:j])
            reqStr = s[j+1: j+1+length]
            res.append(reqStr)
            
            l = j+1+length
        
        return res
            
            
            
