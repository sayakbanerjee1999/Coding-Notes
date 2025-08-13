class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # Greedy - Always sort by ending time because we want to pick the smallest intervals first to accomodate more intervals (max non-overlapping intervals)
        intervals.sort(key = lambda x: (x[1], x[0]))
        
        count = 1
        freeTime = intervals[0][1]
        res = [intervals[0]]
        for i in range(1, len(intervals)):
            # If Start Time >= Ending Time of Last Interval
            if intervals[i][0] >= freeTime:
                count += 1
                freeTime = intervals[i][1]      # Update Ending Time
                # res.append(intervals[i])
            else:
                continue
        
        return (len(intervals) - count)
