# The value of keeping an edge isn't just the edge weight itself. When you keep an edge to a 
# child node, you're also keeping the entire subtree rooted at that child. So the real value 
# of keeping an edge is: edge_weight + optimal_sum_of_child_subtree.

# This leads us to a bottom-up dynamic programming approach using DFS:
# - Start from the leaves and work our way up to the root
# - At each node, calculate the maximum sum we can get from its subtree
# - For each child, we have a choice: include the edge to that child or not
# - If we include the edge, we gain: edge_weight + child_subtree_sum

# The clever part is recognizing that each node needs to return two values:
# - include_parent: Maximum sum when this node uses at most k edges (can connect to parent)
# - exclude_parent: Maximum sum when this node uses at most k-1 edges (reserving one edge for parent connection)
# Why two values? Because when a parent node is considering whether to keep the edge to this child, 
# it needs to know the child's optimal sum when the child reserves an edge for the parent connection (k-1 case).

# At each node, we greedily select the best edges by calculating the "profit" of each edge: 
# edge_weight + child_exclude_parent - child_include_parent. 
# We sort these profits in descending order and take the top k (or k-1) most profitable edges.

# The root node is special because it has no parent, so we can use all k edges for its children. 
# That's why the final answer is the maximum of both values computed for the root.

class Solution:
    def maximizeSumOfWeights(self, edges: List[List[int]], k: int) -> int:
        def dfs(current_node: int, parent_node: int) -> Tuple[int, int]:
            # Base sum without including any edges from current node
            base_sum = 0
          
            # Store potential gains from including edges to children
            edge_gains = []
          
            # Process all neighbors (children in the DFS tree)
            for neighbor, edge_weight in adjacency_list[current_node]:
                # Skip the parent edge to avoid revisiting
                if neighbor == parent_node:
                    continue
              
                # Recursively get the maximum sums for the subtree rooted at neighbor
                sum_with_k, sum_with_k_minus_1 = dfs(neighbor, current_node)
              
                # Add the best sum without considering the edge to this child
                base_sum += sum_with_k
              
                # Calculate the gain from including the edge to this child
                # gain = (edge_weight + child's sum with k-1 edges) - (child's sum with k edges)
                gain = edge_weight + sum_with_k_minus_1 - sum_with_k
              
                # Only store positive gains (edges worth including)
                if gain > 0:
                    edge_gains.append(gain)
          
            # Sort gains in descending order to greedily select the best edges
            edge_gains.sort(reverse=True)
          
            # Calculate maximum sums:
            # 1. When we can use k edges from current node
            max_sum_k_edges = base_sum + sum(edge_gains[:k])
          
            # 2. When we can use k-1 edges (one slot reserved for parent edge)
            max_sum_k_minus_1_edges = base_sum + sum(edge_gains[:k - 1])
          
            return max_sum_k_edges, max_sum_k_minus_1_edges
      
        # Calculate number of nodes (tree has n-1 edges for n nodes)
        num_nodes = len(edges) + 1
      
        # Build adjacency list representation of the tree
        adjacency_list: List[List[Tuple[int, int]]] = [[] for _ in range(num_nodes)]
        for node_u, node_v, weight in edges:
            adjacency_list[node_u].append((node_v, weight))
            adjacency_list[node_v].append((node_u, weight))
      
        # Start DFS from node 0 as root (parent = -1)
        max_with_k, max_with_k_minus_1 = dfs(0, -1)
      
        # Return the maximum of both possibilities
        return max(max_with_k, max_with_k_minus_1)
