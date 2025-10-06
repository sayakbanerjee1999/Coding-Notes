class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        sum_ = sum(x for x in cardPoints[:k])
        maxSum_ = sum_

        idx = len(cardPoints) - 1
        for i in range(k-1, -1, -1):
            # Subtract from Begging
            sum_ -= cardPoints[i]
            # Add from the End
            sum_ += cardPoints[idx]

            idx -= 1
            maxSum_ = max(maxSum_, sum_)
        
        return maxSum_
