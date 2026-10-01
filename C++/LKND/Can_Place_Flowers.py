class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        # Handle Edge Cases separately
        if len(flowerbed) == 1:
            if (flowerbed[0] == 0 and n <= 1) or (n == 0):
                return True
            return False
        

        for i in range(len(flowerbed)):
            # 1st case: 1st Index
            if i==0:
                if flowerbed[i] == 0 and flowerbed[i+1] == 0:
                    n -= 1
                    flowerbed[i] = 1
            elif i==len(flowerbed)-1:
                if flowerbed[i] == 0 and flowerbed[i-1] == 0:
                    n -= 1
                    flowerbed[i] = 1
            else:
                if flowerbed[i] == 0 and flowerbed[i-1] == flowerbed[i+1] == 0:
                    n -= 1
                    flowerbed[i] = 1
        
        return False if n > 0 else True 


# class Solution:
#     def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
#         count = 0
#         for i in range(len(flowerbed)):
#             # Check if the current plot is empty.
#             if flowerbed[i] == 0:
#                 # Check if the left and right plots are empty.
#                 empty_left_plot = (i == 0) or (flowerbed[i - 1] == 0)
#                 empty_right_lot = (i == len(flowerbed) - 1) or (flowerbed[i + 1] == 0)
                
#                 # If both plots are empty, we can plant a flower here.
#                 if empty_left_plot and empty_right_lot:
#                     flowerbed[i] = 1
#                     count += 1
#                     if count >= n:
#                         return True
                    
#         return count >= n
