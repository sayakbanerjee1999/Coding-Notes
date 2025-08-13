#User function Template for python3

class Solution:    
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    # Sweep Line Solution
    def minimumPlatform(self,arr,dep):
        # code here
        data_ = []
        for i in range(len(arr)):
            data_.append([arr[i], dep[i]])
        
        events = []
        for ar, de in data_:
            events.append([ar, +1])
            events.append([de+1, -1])
        
        events.sort(key = lambda x: (x[0], x[1]))
        
        count = 0
        maximum_val = 0
        for time, delta in events:
            count += delta
            maximum_val = max(count, maximum_val)
        
        return maximum_val
