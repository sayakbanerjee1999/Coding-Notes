# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

from typing import List


class Solution:
    def depthSum(self, nestedList: List[NestedInteger]) -> int:
        def calculate_depth_sum(nested_list: List[NestedInteger], depth: int) -> int:
            total_sum = 0

            # Iterate through each element in the current level
            for element in nested_list:
                if element.isInteger():
                    # If it's an integer, add its value multiplied by current depth
                    total_sum += element.getInteger() * depth
                else:
                    # If it's a nested list, recursively process it with increased depth
                    total_sum += calculate_depth_sum(element.getList(), depth + 1)

            return total_sum

        # Start the recursive calculation from depth 1
        return calculate_depth_sum(nestedList, 1)
