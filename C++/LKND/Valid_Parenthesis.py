class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {"(":")", "{":"}", "[":"]"}
        stack = []

        for ch in s:
            if ch in mapping.keys():
                stack.append(ch)
            elif ch in mapping.values():
                # If stack is empty or top element is a mismatch bracket
                if not stack or mapping[stack[-1]] != ch:
                    return False
                stack.pop()

        return True
