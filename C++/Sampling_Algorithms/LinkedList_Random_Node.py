# Reservoir sampling with k = 1

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import random

class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head = head
        self.k = 1

    def getRandom(self) -> int:
        reservoir = self.head.val
        node = self.head.next
        i = 2

        while node:
            if random.randrange(i) == 0:
                reservoir = node.val
            node = node.next
            i += 1
        
        return reservoir




# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
