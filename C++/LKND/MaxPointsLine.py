class Solution:
    def maxPoints(self, points: list[list[int]]) -> int:
        # For each point determine if it lies on the longest line
        # Count all points with the same slope and update the Counter
        # Update Max

        # Guaranteed to have at least 1
        res = 1
        for i in range(len(points)):
            p1 = points[i]
            # Maintain a counter for every individual points and not globally
            # Why not globally; 2 separate points can have a slope of x 
            # and then you update the global counter and not the one relevant to this point
            count = collections.defaultdict(int)
            for j in range(i + 1, len(points)):
                p2 = points[j]

                # Edge Case - Vertical Line (Slope Infinite) [x values are same]
                # Zero Division Error so handle
                if p1[0] == p2[0]:
                    slope = float("inf")
                
                # Horizontal line is not edge case. 
                # Numerator 0 y2 - y1 (Slope = 0)
                else:
                    # y2-y1 / x2-x1
                    slope = (p2[1] - p1[1]) / (p2[0] - p1[0])
                
                count[slope] += 1
                # count[slope] never considers point p1. So add it when taking maximum
                res = max(res, count[slope] + 1)
        
        return res
