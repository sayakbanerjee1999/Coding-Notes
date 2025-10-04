class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        elementFreq = defaultdict(int)

        for num in nums:
            elementFreq[num] += 1

            # Based on the logic that only 2 elements can be present at in such a scenario
            if len(elementFreq) > 2:
                # Make changes on the copied once
                for ele in list(elementFreq.keys()):
                    elementFreq[ele] -= 1

                    if elementFreq[ele] == 0:
                        del elementFreq[ele]
        
        res = []
        # If any value left check if count >
        for ele in elementFreq:
            if nums.count(ele) > len(nums)//3:
                res.append(ele)
        
        return res
