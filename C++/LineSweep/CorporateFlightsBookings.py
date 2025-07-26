# LC - 1109

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
        
        changes_dates = [date for date, _ in changes]

        res = []
        last_value = 0
        change_dict = {date: val for date, val in changes}

        # Fill values for all days from 1 to n including 0's in the beginning
        for day in range(1, n + 1):
            if day in change_dict:
                last_value = change_dict[day]
            res.append(last_value)

        return res
