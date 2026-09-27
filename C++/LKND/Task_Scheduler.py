from collections import *

class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:
        jobMap = defaultdict(int)
        for task in tasks:
            jobMap[task] += 1
        
        # Stores available element
        # We will always do the most frequent task first to reduce idle time
        # However in Python its a minHeap by default. (So push -ve)
        maxH = [-v for k, v in jobMap.items()]
        heapq.heapify(maxH)
        
        # in a Queue - store the remaining frequency of the task and when it is next available
        # Stores unavailable elements
        q = deque()     # [time, freq] -> time when it is next available
        time = 0

        while q or maxH:
            time += 1

            if maxH:
                top = -1 * heapq.heappop(maxH)
                updatedFreq = top - 1
                # If UpdatedFreq > 0 push back to queue with updated available time
                if updatedFreq > 0:
                    q.append([time+n, updatedFreq])
            
            # If elements available in the queue and next availability is current time
            # Push it to the maxH of available elements
            if q and q[0][0] == time:
                _, freq = q[0]
                q.popleft()
                heapq.heappush(maxH, -1 * freq)
        
        return time
