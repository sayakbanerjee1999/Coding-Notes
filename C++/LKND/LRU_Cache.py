# Doubly LinkedList Node
class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev, self.next = None, None


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.lru_cache = {}     # Hashmap where key = key and value is pointer to the node which contains, key, value again

        # Define Dummy Pointers LEFT, RIGHT 
        # Right of Left Pointer stores LRU, Left of Right Pointer stores Most Recent 
        self.left = Node(0, 0)
        self.right = Node(0, 0)
        self.left.next = self.right
        self.right.prev = self.left

    # Utility Function to remove a node
    def remove(self, node: Node) -> None:
        # The LL will always have 3 nodes. Rewire
        p = node.prev
        n = node.next
        p.next, n.prev = n, p
        del node
    
    # Utility Function to insert a node at the Most Recently Used position always
    def insert(self, node: Node) -> None:
        p = self.right.prev
        p.next, node.prev = node, p
        self.right.prev, node.next = node, self.right

    def get(self, key: int) -> int:
        if key in self.lru_cache:
            # Remove then insert as this is most recently used now
            self.remove(self.lru_cache[key])
            self.insert(self.lru_cache[key])
            return self.lru_cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.lru_cache:
            self.remove(self.lru_cache[key])
        
        mru = Node(key, value)
        self.lru_cache[key] = mru
        self.insert(mru)

        # If greater than capacity remove the lru
        if self.capacity < len(self.lru_cache):
            lru = self.left.next               # left->next always has lru
            self.remove(lru)
            # Remove from hashmap as well
            del self.lru_cache[lru.key]



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
