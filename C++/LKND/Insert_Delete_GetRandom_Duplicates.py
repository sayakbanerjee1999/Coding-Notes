import random
from collections import defaultdict

class RandomizedCollection:

    def __init__(self):
        self.arr = []
        
        # LC 380: val -> one index
        # LC 381: val -> SET of indices because duplicates are allowed
        self.indexMap = defaultdict(set)

    def insert(self, val: int) -> bool:
        
        # Add to Array
        self.arr.append(val)
        
        # Store the index of this occurrence
        self.indexMap[val].add(len(self.arr) - 1)
        
        # True only if this was the first occurrence
        return len(self.indexMap[val]) == 1

    def remove(self, val: int) -> bool:
        
        if val not in self.indexMap:
            return False
        
        # Find ANY index of the value we want to remove
        idx = next(iter(self.indexMap[val]))
        
        # Find the last element
        last_element = self.arr[-1]
        last_idx = len(self.arr) - 1

        # --------------------------------------------------
        # Remove the occurrence we are deleting from its set
        # --------------------------------------------------
        self.indexMap[val].remove(idx)

        # --------------------------------------------------
        # Same swap-with-last trick as LC 380
        # --------------------------------------------------
        if idx != last_idx:

            # Copy last element to the index we are removing
            self.arr[idx] = last_element

            # --------------------------------------------------
            # DIFFERENCE FROM LC 380:
            #
            # last_element can have multiple indices.
            # Remove its old last index and add its new index.
            #
            # IMPORTANT:
            # This also works when val == last_element.
            # --------------------------------------------------
            self.indexMap[last_element].remove(last_idx)
            self.indexMap[last_element].add(idx)

        # Pop the last element
        self.arr.pop()

        # If no more occurrences of val exist,
        # remove val completely from the dictionary.
        if not self.indexMap[val]:
            del self.indexMap[val]

        return True

    def getRandom(self) -> int:
        x = random.randint(0, len(self.arr) - 1)
        return self.arr[x]
