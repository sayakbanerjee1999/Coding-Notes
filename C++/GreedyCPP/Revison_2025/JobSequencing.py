class Solution:
    def jobSequencing(self, deadline, profit):
        # code here
        jobs = [[profit[i], deadline[i]] for i in range(len(deadline))]
        deadlines_array = [-1]*(max(deadline))
        jobs.sort(key = lambda x: x[0], reverse = True)
        
        # print(deadlines_array)
        # print(jobs)
        
        total_profit = 0
        total_jobs = 0
        for p, d in jobs:
            ind = d-1
            for i in range(ind, -1, -1):
                if deadlines_array[i] == -1:
                    total_jobs += 1
                    total_profit += p
                    deadlines_array[i] = p
                    break
        
        return [total_jobs, total_profit]


# Might give TLE. Use disjoint set
