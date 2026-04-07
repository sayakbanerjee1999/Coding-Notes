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
