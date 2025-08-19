class Solution:
    def countBouquets(self, bloomDay: List[int], k: int, days: int) -> int:
        count = 0

        # # My Logic Below GIVES TLE (O(N^2))
        # idx = 0
        # while idx <= len(bloomDay) - k:
        #     if all(bloomDay[j] <= days for j in range(idx, idx + k)):
        #         count += 1
        #         idx += k        # Skip only if contributing to picking flowers
        #     else:
        #         idx += 1
        
        flowers = 0

        for b in bloomDay:
            if b <= days:
                flowers += 1
                if flowers == k:    # Form a Bouquet
                    count += 1
                    flowers = 0
            else:
                flowers = 0         # Break the Chain
        
        return count
        

    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        low = min(bloomDay)
        high = max(bloomDay)
        ans = 10e9

        while low <= high:
            mid = low + (high - low)//2

            if self.countBouquets(bloomDay, k, mid) >= m:
                ans = mid
                high = mid - 1          # Minimize your answer

            else:
                low = mid + 1 
        
        return -1 if ans == 10e9 else ans

        
