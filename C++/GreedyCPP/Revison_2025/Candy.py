class Solution:
    def candy(self, ratings: List[int]) -> int:
        # Simple Solution. Check left neighbor and right neighbor separately 
        # n = len(ratings)
        # left = [0]*n
        # left[0] = 1

        # for i in range(1, n):
        #     if ratings[i] > ratings[i-1]:
        #         left[i] = left[i-1]+1
        #     else:
        #         left[i] = 1
        
        # right = [0]*n
        # right[n-1] = 1
        # for i in range(n-2, -1, -1):
        #     if ratings[i] > ratings[i+1]:
        #         right[i] = right[i+1] + 1
        #     else:
        #         right[i] = 1
        
        # sum = 0
        # for i in range(len(left)):
        #     sum += max(left[i], right[i])
        
        # # Space - O(2n) for above solution
        
        # # Optimizing to O(n) by calculating sum of the fly 
        # right = 1
        # sum = max(right, left[n-1])
        # for i in range(n-2, -1, -1):
        #     if ratings[i] > ratings[i+1]:
        #         right = right+1
        #     else:
        #         right = 1
        #     sum += max(right, left[i])
        
        # SC - O(1) - Slope Based Solution
        # Go Up -> If Increasing. Start peak from 1 and go up
        # While going down also start 1 (you need sum so order of numbers do not matter - Remember Striver Example) But if Down > Peak add that to the sum. 
        # If Peak > Down no need to add that
        sum = 1
        n = len(ratings)
        i = 1
        while i < n:
            if(ratings[i] == ratings[i-1]):
                sum += 1
                i += 1
            peak = 1
            while i < n and ratings[i] > ratings[i-1]:
                peak += 1
                sum += peak
                i += 1
            
            down = 1
            while i < n and ratings[i] < ratings[i-1]:
                sum += down
                down += 1
                i += 1
            
            if down > peak:
                sum += (down - peak)
        
        return sum
        
