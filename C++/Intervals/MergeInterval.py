class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        intervals.sort(key = lambda x: x[0])
        res = [intervals[0]]
        for start, end in intervals[1:]:
            if start <= res[-1][1]:
                updatedEnd = max(res[-1][1], end)
                res[-1][1] = updatedEnd
            else:
                res.append([start, end])
        
        return res
