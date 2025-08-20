class Solution:
    def search(self, arr: List[int], target: int) -> int:
        lo = 0
        hi = len(arr) - 1

        ans = -1

        while(lo <= hi):
            mid = lo + (hi - lo) // 2

            if arr[mid] == target:
                ans = mid
            
            # Left Half Sorted
            if arr[lo] <= arr[mid]:
                if target >= arr[lo] and target < arr[mid]:
                    hi = mid - 1
                else:
                    lo = mid + 1

            else:
                if target <= arr[hi] and target > arr[mid]:
                    lo = mid + 1
                else:
                    hi = mid - 1
        
        return ans

            
