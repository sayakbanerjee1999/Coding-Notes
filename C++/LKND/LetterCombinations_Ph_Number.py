# Backtracking Solution
# O(4^n) -> better
# class Solution:
#     def letterCombinations(self, digits: str) -> List[str]:
#         if not digits:
#             return []

#         phone = [
#             "",     # 0
#             "",     # 1
#             "abc",  # 2
#             "def",  # 3
#             "ghi",  # 4
#             "jkl",  # 5
#             "mno",  # 6
#             "pqrs", # 7
#             "tuv",  # 8
#             "wxyz"  # 9
#         ]

#         result = []

#         def backtrack(index, path):
#             if index == len(digits):
#                 result.append("".join(path))
#                 return

#             letters = phone[int(digits[index])]

#             for letter in letters:
#                 path.append(letter)
#                 backtrack(index + 1, path)
#                 path.pop()

#         backtrack(0, [])

#         return result

# O(n * 4^n) -> 4 letters at worst

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        digit_to_letters = [
            "abc",   # 2
            "def",   # 3
            "ghi",   # 4
            "jkl",   # 5
            "mno",   # 6
            "pqrs",  # 7
            "tuv",   # 8
            "wxyz"   # 9
        ]

        res = [""]
        for digit in digits:
            letters = digit_to_letters[int(digit)-2]

            # Generate all combinations by appending each letter 
            # to all existing combinations
            # res = [existing + letter 
            #          for existing in res 
            #          for letter in letters]
            new_res = []

            for existing in res:
                for letter in letters:
                    new_res.append(existing + letter)

            res = new_res
        
        return res
