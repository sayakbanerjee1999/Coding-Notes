# Approach:
# The problem can be solved using a greedy approach. First, we sort the input array in decreasing order. 
# Then, we iterate over the array and calculate the prefix sums of the elements, adding each prefix sum to the result as long as it 
# remains non-negative. If the prefix sum becomes negative at any point, we stop the iteration and return the current result.

# Intuition:
# The intuition behind the greedy approach is that the maximum satisfaction value is obtained by serving the most popular dishes first, 
# and the least popular dishes last. By sorting the dishes in decreasing order of popularity, we can ensure that we serve the 
# most popular dishes first, and thus maximize the satisfaction value.

# Next, we calculate the prefix sums of the sorted dishes, starting from the most popular dish. The prefix sum at index i represents 
# the total satisfaction value obtained by serving the i most popular dishes in decreasing order. If the prefix sum at any point 
# becomes negative, it means that the remaining dishes have a net negative contribution to the total satisfaction value, and we can stop serving them.

# By stopping the iteration as soon as the prefix sum becomes negative, we can ensure that we don't serve any dishes that have a 
# net negative contribution to the total satisfaction value. This allows us to obtain the maximum satisfaction value while 
# minimizing the number of dishes served.

class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        n = len(satisfaction)
        prefixSum, res = 0, 0

        satisfaction.sort(reverse = True)

        for i in satisfaction:
            prefixSum += i
            if prefixSum < 0:
                return res
            res += prefixSum
        
        return res
