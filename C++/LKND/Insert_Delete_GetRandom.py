class RandomizedSet:

    def __init__(self):
        self.arr = []
        self.indexMap = defaultdict(int)

    def insert(self, val: int) -> bool:
        if val in self.arr:
            return False
        
        # Add to Array; Ad
        self.arr.append(val)
        self.indexMap[val] = len(self.arr) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.indexMap:
            return False
        
        # Find Index of the current element
        # Find out the Last Element
        # Copy the last element to the idx
        # Update the last element's index in indexMap to idx
        idx = self.indexMap[val]
        last_element = self.arr[-1]

        self.arr[idx] = last_element
        self.indexMap[last_element] = idx

        # Pop the Last Element and delete from Dictionary 
        self.arr.pop()
        del self.indexMap[val]

        return True

    def getRandom(self) -> int:
        x = random.randint(0, len(self.arr) - 1)
        return self.arr[x]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
