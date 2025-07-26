// LC - 2848

class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        carsPresent = []
        
        for start, end in nums:
            carsPresent.append((start, +1))
            carsPresent.append((end+1, -1))
        
        carsPresent.sort(key = lambda x: (x[0], x[1]))
        
        changes = []
        count = 0
        for point, delta in carsPresent:
            count += delta
            changes.append((point, count))
        
        total = 0
        # If prev point is 0. Then from that point to current point there are no cars so do not line in the count
        for i in range(1, len(changes)):
            prev_point, prev_count = changes[i - 1]
            curr_point, _ = changes[i]
            
            if prev_count > 0:
                total += curr_point - prev_point

        return total
