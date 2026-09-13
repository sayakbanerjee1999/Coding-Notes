# Word Ladder — Very Short Logic Note

# Core idea: BFS on a graph

# Treat each word as a node.
# Two words are connected if they differ by exactly 1 character.
# Build an adjacency list efficiently using patterns like:
# hot → *ot, h*t, ho*
# Words sharing the same pattern are neighbors.
# Start BFS from beginWord.
# For each word, visit all its unvisited neighbors and add them to the queue.
# The first time we reach endWord, we have the shortest transformation because BFS explores level-by-level.
# Maintain a visited set so we don't revisit words.

# Mental model:

# hit
#  ↓
# hot
#  ↓
# dot / lot
#  ↓
# dog / log
#  ↓
# cog

# Why BFS?
# Every transformation has equal cost (one letter change), so BFS naturally finds the shortest path.


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList: 
            return 0
        
        wordList.append(beginWord)

        # Create the adjacency list
        # O(n * m * m) -> n = number of words; m = length of word
        neighbor = collections.defaultdict(list)
        for word in wordList:
            for j in range(len(word)):
                # Create the patter
                pattern = word[:j] + "*" + word[j+1:]
                neighbor[pattern].append(word)          # The word belongs to the pattern
        
        # Now the BFS search -> Because guaranteed to reach destination 
        visited = set([beginWord])      # Maintain to avoid loops
        q = deque([beginWord])
        res = 1

        while q:
            for i in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return res
                
                # Build the pattern for the current word. 
                # Find its neighbors and iterate through
                for j in range(len(word)):
                    patt = word[:j] + "*" + word[j+1:]
                    neighs = neighbor[patt]
                    for neigh in neighs:
                        # If neigh not in visited to avoid loop
                        if neigh not in visited:
                            q.append(neigh)
                            visited.add(neigh)
            res += 1
        
        return 0
