#User function Template for python3

class Solution:
    
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,start,end):
        # code here
        meetings = [[start[i], end[i]] for i in range(len(start))]
        # Always sort by ending time because we want to pick the smallest intervals first to accomodate more meetings
        # Greedy
        meetings.sort(key = lambda x: x[1]) 
        
        freeTime = meetings[0][1]
        count = 1
        for i in range(1, len(meetings)):
            if meetings[i][0] > freeTime:
                count += 1
                freeTime = meetings[i][1]
            else:
                continue
        
        return count
