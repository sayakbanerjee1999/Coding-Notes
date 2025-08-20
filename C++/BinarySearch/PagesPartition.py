class Solution:
    def splitBooks(self, arr, val) -> int:
        numStudents = 1
        numPages = 0
        
        for pages in arr:
            if (numPages + pages <= val):
                numPages += pages
            else:
                numStudents += 1
                numPages = pages        # start new student with this book
        
        return numStudents
    
    def findPages(self, arr, k):
        # code here
        if len(arr) < k:
            return -1
            
        lo = max(arr)
        hi = sum(ele for ele in arr)
        
        ans = -1
        while(lo <= hi):
            mid = lo + (hi-lo)//2
            
            students =  self.splitBooks(arr, mid)
            
            if students <= k:
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        
        return ans
