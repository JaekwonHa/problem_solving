class MyCalendar:

    def __init__(self):
        self.treeSize = 1000000001
        self.tree = [0 for _ in range(self.treeSize*2)]

    def book(self, start: int, end: int) -> bool:
        res = 0

        left = start + self.treeSize
        right = end + self.treeSize
        while left < right:
            if left % 2 == 1:
                res = max(res, self.tree[left])
                left += 1
            if right % 2 == 1:
                right -= 1
                res = max(res, self.tree[right])
            left //= 2
            right //= 2

        if res > 0:
            return False

        left = start + self.treeSize
        right = end + self.treeSize
        while left < right:
            if left % 2 == 1:
                self.tree[left] = 1
                left += 1
            if right % 2 == 1:
                right -= 1
                self.tree[right] = 1
            left //= 2
            right //= 2

        return True


# Your MyCalendar object will be instantiated and called as such:
obj = MyCalendar()
print(obj.book(10, 20))
print(obj.book(15, 25))
print(obj.book(20, 30))
