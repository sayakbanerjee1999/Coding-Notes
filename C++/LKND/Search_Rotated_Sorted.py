class Solution:
    def search(self, arr: List[int], target: int) -> int:
        lo = 0
        hi = len(arr) - 1

        ans = -1
        while lo <= hi:
            mid = lo + (hi - lo) // 2

            if arr[mid] == target:
                ans = mid

            # One half of the array will always be sorted after rotation since the initial array was itself sorted
            # So we will compare lo, mid initially; if arr[lo] <= arr[mid] - it means left side is sorted
            
            # Target >= arr[lo]  /  target <= arr[hi]
            # Important edge cases; Shouldn't be simple > / <
            # Left Half sorted
            if arr[lo] <= arr[mid]:
                if target < arr[mid] and target >= arr[lo]:
                    hi = mid - 1
                else:
                    lo = mid + 1
            
            # Right Half sorted
            else:
                if target > arr[mid] and target <= arr[hi]:
                    lo = mid + 1
                else:
                    hi = mid - 1
        
        return ans
