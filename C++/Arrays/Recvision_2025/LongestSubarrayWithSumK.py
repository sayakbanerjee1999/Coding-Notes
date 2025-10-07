class Solution:
    def subarraySum(self, arr: List[int], k: int) -> int:
        sumsMap = {}
        maxLen = 0
        sumSoFar = 0

        for i in range(len(arr)):
            sumSoFar += arr[i]

            # Case 1: subarray from index 0 to i has sum = k
            if sumSoFar == k:
                maxLen = i + 1

            # Case 2: check if there exists a prefix sum = sumSoFar - k
            if (sumSoFar - k) in sumsMap:
                maxLen = max(maxLen, i - sumsMap[sumSoFar - k])

            # Case 3: store first occurrence of prefix sum
            if sumSoFar not in sumsMap:
                sumsMap[sumSoFar] = i

        return maxLen
