class Solution:
    def getFactors(self, n: int) -> List[List[int]]:
        def dfs(target: int, start_factor: int) -> None:
            # If we have factors in current_path, add this combination
            # (current factors + remaining target as last factor)
            if current_path:
                result.append(current_path + [target])

            # Try all possible factors from start_factor up to sqrt(target)
            factor = start_factor
            while factor * factor <= target:
                # If factor divides target evenly
                if target % factor == 0:
                    # Add factor to current path
                    current_path.append(factor)
                    # Recursively find factors for the quotient
                    # Use 'factor' as start to avoid duplicate combinations
                    dfs(target // factor, factor)
                    # Backtrack - remove the factor we just tried
                    current_path.pop()
                factor += 1

        # Initialize tracking variables
        current_path = []  # Stores current combination of factors being explored
        result = []        # Stores all valid factor combinations

        # Start DFS with the original number and minimum factor of 2
        dfs(n, 2)

        return result
