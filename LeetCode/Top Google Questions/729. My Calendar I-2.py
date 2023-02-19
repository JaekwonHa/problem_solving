from sortedcontainers import SortedList


class MyCalendar:

    def __init__(self):
        self.sortedList = SortedList()

    def book(self, start: int, end: int) -> bool:
        if len(self.sortedList) == 0:
            self.sortedList.add((start, end))
            return True

        upper_bound = self.sortedList.bisect_right((start, end))
        left = upper_bound-1
        right = upper_bound

        if left != -1 and start < self.sortedList[left][1]:
            return False
        if right != len(self.sortedList) and self.sortedList[right][0] < end:
            return False
        self.sortedList.add((start, end))
        return True



# Your MyCalendar object will be instantiated and called as such:
obj = MyCalendar()

print(obj.book(10 ,20))
print(obj.book(15, 25))
print(obj.book(20, 30))