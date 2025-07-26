# LC - 

class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        seats = []
        for start, end, reserved in bookings:
            seats.append([start, reserved])
            seats.append([end+1, -reserved])
        
        seats.sort(key = lambda x: (x[0], x[1]))

        changes = []
        count = 0
        for point, delta in seats:
            if point > n:
                continue
            count += delta
            if changes and changes[-1][0] == point:
                changes[-1][1] = count
            else:
                changes.append([point, count])
        
        res = []
        idx = 0
        # Ensures all the days in between are also taken into account even if no changes in flight bookings
        for day in range(1, n + 1):
            while idx + 1 < len(changes) and changes[idx + 1][0] <= day:
                idx += 1
            if day < changes[0][0]:
                res.append(0)
            else:
                res.append(changes[idx][1])

        return res
