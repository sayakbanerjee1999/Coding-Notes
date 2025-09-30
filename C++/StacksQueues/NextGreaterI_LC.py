class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mapping = {}
        stack = []

        for i in range(len(nums2)-1, -1, -1):
            while len(stack)>0 and nums2[i] >= stack[-1]:
                stack.pop()
            
            mapping[nums2[i]] = -1 if len(stack) == 0 else stack[-1]

            stack.append(nums2[i])
        
        res = [0]*len(nums1)
        for i in range(len(nums1)):
            res[i] = mapping[nums1[i]]
        
        return res
