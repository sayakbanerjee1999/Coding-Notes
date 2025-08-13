from collections import defaultdict
class MyCalendar:

    def __init__(self):
        self.bookings = defaultdict(int)

    def book(self, startTime: int, endTime: int) -> bool:
        self.bookings[startTime] += 1
        self.bookings[endTime] -= 1

        active = 0
        for key, count in sorted(self.bookings.items()):
            active += count

            if active >= 2:
                self.bookings[startTime] -= 1
                self.bookings[endTime] += 1
                return False
        
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)
