class Solution:
    def sortTransformedArray(
        self, nums: List[int], a: int, b: int, c: int
    ) -> List[int]:
        def quadratic_transform(x: int) -> int:
            """Calculate the quadratic transformation of x."""
            return a * x * x + b * x + c

        n = len(nums)
        result = [0] * n

        # Two pointers approach from both ends
        left = 0
        right = n - 1

        # Determine filling direction based on parabola shape
        # If a < 0 (downward parabola): fill from start because the ends have the minimimum values (smaller values first)
        # If a >= 0 (upward parabola or line): fill from end because the extremes have the largest value (larger values first)
        index = 0 if a < 0 else n - 1

        while left <= right:
            left_value = quadratic_transform(nums[left])
            right_value = quadratic_transform(nums[right])

            if a < 0:
                # Downward parabola: pick smaller value and fill from start
                if left_value <= right_value:
                    result[index] = left_value
                    left += 1
                else:
                    result[index] = right_value
                    right -= 1
                index += 1
            else:
                # Upward parabola or line: pick larger value and fill from end
                if left_value >= right_value:
                    result[index] = left_value
                    left += 1
                else:
                    result[index] = right_value
                    right -= 1
                index -= 1

        return result
