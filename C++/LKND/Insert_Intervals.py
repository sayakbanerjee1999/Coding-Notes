class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # First Part (Non-Overlapping)
        idx = 0
        res = []
        n = len(intervals)
        while idx < n and intervals[idx][1] < newInterval[0]:
            res.append(intervals[idx])
            idx += 1
        
        # 2nd Half Overlapping
        # If starting point of a interval is <= the ending point of the newInterval - there is surely an overlap
        while idx < n and intervals[idx][0] <= newInterval[1]:
            newInterval[0] = min(intervals[idx][0], newInterval[0])
            newInterval[1] = max(intervals[idx][1], newInterval[1])
            idx += 1
        res.append(newInterval)

        while idx < n:
            res.append(intervals[idx])
            idx += 1
        
        return res
        

        
