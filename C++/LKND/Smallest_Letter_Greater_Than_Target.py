# Transform into a Binary Search Problem

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        left, right = 0, n - 1
        first_true_index = -1

        # Binary search to find the first index where letters[mid] > target
        while left <= right:
            mid = (left + right) // 2

            # Feasible condition: is this character greater than target?
            if letters[mid] > target:
                first_true_index = mid  # Record potential answer
                right = mid - 1  # Search left for smaller valid index
            else:
                left = mid + 1  # Search right

        # Handle wrap-around: if no character is greater, return first character
        if first_true_index == -1:
            return letters[0]
        return letters[first_true_index]
