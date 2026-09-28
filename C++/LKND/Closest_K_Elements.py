# Compare:
# x - arr[mid] vs arr[mid+k] - x
# Whichever side is farther gets eliminated.

# For any window of k elements:
# arr[mid] ........ arr[mid+k-1]

# To decide whether to move the window right, we compare:
# left candidate:  arr[mid]
# right candidate: arr[mid+k]

# If:
# x - arr[mid] > arr[mid + k] - x
# then the left candidate is farther from x, so move right:
# left = mid + 1

# Otherwise, keep/move toward the left:
# right = mid

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        left = 0
        right = len(arr) - k

        while left < right:
            mid = (left + right) // 2

            # Compare the two possible windows:[mid, mid+k-1] vs [mid+1, mid+k]
            # The worst element k ele away is still better the current one (mid): so move left to mid+1 
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid

        return arr[left:left + k]
