class Solution:
    def subarraySum(self, arr: List[int], k: int) -> int:
        count = 0
        sumSoFar = 0
        prefixCount = defaultdict(int)  # to handle subarrays starting at index 0
        prefixCount[0] = 1

        for num in arr:
            sumSoFar += num

            if (sumSoFar - k) in prefixCount:
                count += prefixCount[sumSoFar - k]

            prefixCount[sumSoFar] += 1

        return count
