rom heapq import heappush, heappop, heapify
from typing import List

class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        idle_servers = [(weight, index) for index, weight in enumerate(servers)]
        heapify(idle_servers)
        busy_servers = []
        result = []
      
        for task_index, task_duration in enumerate(tasks):
            # Free ALL servers that are available by current time
            while busy_servers and busy_servers[0][0] <= task_index:
                available_time, server_weight, server_index = heappop(busy_servers)
                heappush(idle_servers, (server_weight, server_index))
          
            if idle_servers:
                server_weight, server_index = heappop(idle_servers)
                heappush(busy_servers, (task_index + task_duration, server_weight, server_index))
            else:
                # Use server's available_time, not current task_index
                available_time, server_weight, server_index = heappop(busy_servers)
                heappush(busy_servers, (available_time + task_duration, server_weight, server_index))
          
            result.append(server_index)
      
        return result


# O(nlogn + mlogn)
