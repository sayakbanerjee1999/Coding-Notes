import heapq

class MedianFinder:

    def __init__(self):
        # small -> max heap
        # Python has only min heap, so store negative values
        self.small = []

        # large -> min heap
        self.large = []

    def addNum(self, num: int) -> None:

        # By default, add the number to the small max heap.
        # Store negative because heapq is a min heap.
        heapq.heappush(self.small, -num)

        # Make sure every number in small <= every number in large.
        #
        # small[0] is the largest number in small
        # -large[0] is the smallest number in large
        if self.small and self.large and -self.small[0] > self.large[0]:
            value = -heapq.heappop(self.small)
            heapq.heappush(self.large, value)

        # If small has more than 1 extra element,
        # move its largest element to large.
        if len(self.small) > len(self.large) + 1:
            value = -heapq.heappop(self.small)
            heapq.heappush(self.large, value)

        # If large has more than 1 extra element,
        # move its smallest element to small.
        if len(self.large) > len(self.small) + 1:
            value = heapq.heappop(self.large)
            heapq.heappush(self.small, -value)

    def findMedian(self) -> float:

        # Odd number of elements:
        # small has the extra element.
        if len(self.small) > len(self.large):
            return -self.small[0]

        # Odd number of elements:
        # large has the extra element.
        if len(self.large) > len(self.small):
            return self.large[0]

        # Even number of elements:
        # Average of the two middle elements.
        return (-self.small[0] + self.large[0]) / 2.0


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
