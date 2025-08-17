class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        sum_ = sum(x for x in cardPoints[:k])
        maxsum = sum_

        idx = len(cardPoints)-1
        for i in range(k-1, -1, -1):
            sum_ -= cardPoints[i]
            sum_ += cardPoints[idx]

            maxsum = max(maxsum, sum_)
            idx = idx - 1

        return maxsum
