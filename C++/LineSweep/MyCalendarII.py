from collections import defaultdict

class MyCalendarTwo:

    def __init__(self):
        self.booking = defaultdict(int)

    def book(self, startTime: int, endTime: int) -> bool:
        self.booking[startTime] += 1
        self.booking[endTime] -= 1

        active_bookings = 0
        for time, count in sorted(self.booking.items()):
            active_bookings += count

            if active_bookings >= 3:
                self.booking[startTime] -= 1
                self.booking[endTime] += 1
                return False

        return True        


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(startTime,endTime)
