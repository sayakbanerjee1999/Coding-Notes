# Since we're going to answer multiple queries on the same array, we can optimize by preprocessing 
# the data once during initialization. The key observation is that we need to know where each word 
# appears in the array. By storing these positions upfront, we can avoid repeatedly scanning the entire array.

# Once we have the positions of both words, we need to find the closest pair of indices. If word1 appears 
# at positions [1, 5, 9] and word2 appears at positions [3, 7, 11], we need to find the minimum of all 
# possible distances: |1-3|, |1-7|, |1-11|, |5-3|, |5-7|, |5-11|, |9-3|, |9-7|, |9-11|.

# Computing all pairwise distances would take O(m * n) time. But notice that these position lists are 
# sorted! 
# This is natural because we collected them by iterating through the array from left to right - so we can use a 2-pointer


from collections import defaultdict
from typing import List
import math

class WordDistance:
    def __init__(self, wordsDict: List[str]):
        """
        Initialize the WordDistance object with a list of words.
        Store the indices of each word for efficient lookup.

        Args:
            wordsDict: List of strings representing words in a document
        """
        # Dictionary to store list of indices for each word
        self.word_indices = defaultdict(list)

        # Store the index of each word occurrence
        for index, word in enumerate(wordsDict):
            self.word_indices[word].append(index)

    def shortest(self, word1: str, word2: str) -> int:
        """
        Find the shortest distance between two words in the original list.
        Uses two-pointer technique to efficiently find minimum distance.

        Args:
            word1: First word to find
            word2: Second word to find

        Returns:
            The minimum distance between any occurrence of word1 and word2
        """
        # Get the sorted lists of indices for both words
        indices1 = self.word_indices[word1]
        indices2 = self.word_indices[word2]

        # Initialize minimum distance to infinity
        min_distance = math.inf

        # Two pointers to traverse both index lists
        pointer1 = 0
        pointer2 = 0

        # Use two-pointer technique to find minimum distance
        while pointer1 < len(indices1) and pointer2 < len(indices2):
            # Calculate distance between current indices
            current_distance = abs(indices1[pointer1] - indices2[pointer2])
            min_distance = min(min_distance, current_distance)

            # Move the pointer pointing to the smaller index
            # This ensures we check all possible pairs efficiently
            if indices1[pointer1] <= indices2[pointer2]:
                pointer1 += 1
            else:
                pointer2 += 1

        return min_distance


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(wordsDict)
# param_1 = obj.shortest(word1, word2)
