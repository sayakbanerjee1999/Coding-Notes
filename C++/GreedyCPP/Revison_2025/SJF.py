#User function Template for python3

class Solution:
    def solve(self, bt):
        # Code here
        bt.sort()
        
        total_waiting_time = 0
        time = 0
        # Total Waiting Time for next is the sum of the current time + time required to finish the job earlier in the queue
        for p in bt:
            total_waiting_time += time
            time += p
        
        return total_waiting_time // len(bt)
