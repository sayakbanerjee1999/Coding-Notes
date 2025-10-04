class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        maxArea = 0

        while l < r:
            area = min(height[l], height[r]) * (r-l)
            maxArea = max(area, maxArea)

            # Water is always bounded by the smaller element
            # So move it and keep the bigger element fixed
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        
        return maxArea
        
