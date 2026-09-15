class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if '0000' in deadends:
            return -1
        
        def children(lock):
            """"Helper Function to Generate the 8 Children 
            combination of the Lock by rotating a wheel once
            Why 8? Every wheel position can be rotated +1/-1
            So essentially 4 * 2 """
            res = []
            for i in range(4):
                # %10 ? 9 + 1 = 10 % 10 = 0 -> Correct 
                digit = str((int(lock[i]) + 1) % 10)
                res.append(lock[:i] + digit + lock[i+1:])
                # +10 ? 0 - 1 = -1 + 10 = 9 % 10 = 9 -> Correct
                digit = str((int(lock[i]) - 1 + 10) % 10)
                res.append(lock[:i] + digit + lock[i+1:])
            return res

        # Queue stores what the lock reads + the number of turns 
        # it required to reach there
        q = deque()
        q.append(["0000", 0])

        # Visited Set -> The new number should not already be visited + 
        # it should not be one amongst the deadends so initializing visited with deadends
        visited = set(deadends)

        while q:
            lock, turn = q.popleft()
            if lock == target:
                return turn

            for child in children(lock):
                if child not in visited:
                    visited.add(child)
                    q.append([child, turn+1])
        
        return -1
