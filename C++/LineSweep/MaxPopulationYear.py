// LC 1854

class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        events = []
        for birth, death in logs:
            events.append((birth, 1))
            events.append((death, -1))
        
        events.sort(key = lambda x: (x[0], x[1])) 

        population_changes = []
        count = 0
        for year, delta in events:
            count += delta
            population_changes.append((year, count))
        
        # Sort by the second element and return the first year with maximum
        population_changes.sort(key = lambda x: x[1], reverse = True)
        return population_changes[0][0]

        
