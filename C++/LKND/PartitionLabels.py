class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        # The key insight is that for each letter in the string, we need 
        # to know where it last appears. Why? Because once we include a letter 
        # in a partition, we must extend that partition at least until the last 
        # occurrence of that letter to ensure it doesn't appear in any other partition.
        lastOccurenceMap = {char: idx for idx, char in enumerate(s)}

        maxLastIndex = 0
        partitionStart = 0
        res = []

        for idx, char in enumerate(s):
            maxLastIndex = max(maxLastIndex, lastOccurenceMap[char])

            # If maxLastIndex is the current index -> we have reached the end of the current partition
            if maxLastIndex == idx:
                currPartitionSize = (idx - partitionStart + 1)
                res.append(currPartitionSize)
                partitionStart = idx + 1
        
        return res
