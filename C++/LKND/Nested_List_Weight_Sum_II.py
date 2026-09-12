# The NestedInteger interface provides methods to check if an element is an integer (isInteger()), 
# get the integer value (getInteger()), or get the nested list (getList()).

# The key insight is recognizing that calculating weights directly would require two passes 
# through the nested list: first to find the maximum depth, then to calculate the weighted sum. 
# But we can be clever about this.

# Let's think about what we're actually computing. For each integer with value v at depth d, 
# its contribution to the final sum is v × (maxDepth - d + 1). If we expand this:

# v × (maxDepth - d + 1)
# = v × maxDepth - v × d + v
# If we sum this across all integers, we get:

# (sum of all v × maxDepth) - (sum of all v × d) + (sum of all v)
# maxDepth × (sum of all v) - (sum of all v × d) + (sum of all v)
# (maxDepth + 1) × (sum of all v) - (sum of all v × d)
# This transformation is brilliant because it separates our calculation into two parts:

# s: The simple sum of all integers
# ws: The weighted sum where each integer is multiplied by its depth
# Hence this can be achieved in a single pass.

class Solution:
    def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
        def traverse_nested_list(nested_integer, current_depth):
            nonlocal max_depth, total_sum, weighted_sum_by_depth
            max_depth = max(max_depth, current_depth)

            if nested_integer.isInteger():
                integer_value = nested_integer.getInteger()
                total_sum += integer_value  # Sum of all integers
                weighted_sum_by_depth += integer_value * current_depth  # Sum weighted by depth
            else:
                for nested_element in nested_integer.getList():
                    traverse_nested_list(nested_element, current_depth + 1)

        # Initialize tracking variables
        max_depth = 0  # Maximum depth found in the nested structure
        total_sum = 0  # Sum of all integers regardless of depth
        weighted_sum_by_depth = 0  # Sum of integers weighted by their depth

        # Process each top-level element in the nested list
        for nested_element in nestedList:
            traverse_nested_list(nested_element, 1)

        return (max_depth + 1) * total_sum - weighted_sum_by_depth
