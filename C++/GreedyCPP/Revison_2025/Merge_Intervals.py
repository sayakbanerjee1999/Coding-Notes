class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []

        intervals.sort(key=lambda x: x[0])  # sort by start time
        res = [intervals[0]]

        for start, end in intervals[1:]:
            if start <= res[-1][1]:  # overlap
                res[-1][1] = max(res[-1][1], end)
            else:  # no overlap
                res.append([start, end])

        return res
