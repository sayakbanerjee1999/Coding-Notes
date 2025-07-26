# LC 3169

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        events = []
        for start, end in meetings:
            events.append([start, 1])
            events.append([end+1, -1])
        
        events.sort(key = lambda x: (x[0], x[1]))

        count = 0
        changes = []
        for point, delta in events:
            if point > days:        # Do not take into accunt point outside availability
                continue
            count += delta
            if changes and changes[-1][0] == point:
                changes[-1][1] = count
            else:
                changes.append([point, count])
        print(changes)
        
        numDays = 0
        for i in range(len(changes)-1):
            if changes[i][1] == 0:
                nextMeetingDay = changes[i+1][0]
                numDays += (nextMeetingDay - changes[i][0])
        
        # Handle the Case when the last element is 0 and is < days
        if changes[-1][1] == 0:
            numDays += (days - changes[-1][0] + 1)
        
        # Handle the Case when the first meeting starts at a later date
        if changes[0][0] > 1:
            numDays += (changes[0][0] - 1)
        
        return numDays
