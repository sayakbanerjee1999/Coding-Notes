import bisect

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        tracking = []
        for start, end in flowers:
            tracking.append([start, 1])
            tracking.append([end+1, -1])
        
        tracking.sort(key = lambda x: x[0])
        
        count = 0
        changes_list = []
        for point, delta in tracking:
            count += delta
            if changes_list and changes_list[-1][0] == point:
                changes_list[-1][1] = count
            else:
                changes_list.append([point, count])
        
        # For the given list of people the nearest right element for insertion
        pt = [i[0] for i in changes_list]
        cnt = [i[1] for i in changes_list]

        print(pt)
        see = []
        for pos in people:
            idx = bisect.bisect_right(pt, pos)
            if idx == 0:
                see.append(0)               # Edge Case
            else:
                see.append(cnt[idx-1])
        
        return see        
