class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        res = []

        # Python has only a min-heap.
        # Store negative distance to simulate a max-heap.
        max_heap = []

        for x, y in points:
            distance = x*x + y*y

            # Push (-distance, x, y)
            heapq.heappush(max_heap, (-distance, x, y))

            # Keep only k closest points
            if len(max_heap) > k:
                heapq.heappop(max_heap)

        # Extract points from heap
        while max_heap:
            distance, x, y = heapq.heappop(max_heap)
            res.append([x, y])

        return res
