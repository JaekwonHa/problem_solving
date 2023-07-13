class MinStack:

    def __init__(self):
        self.st = []

    def push(self, val: int) -> None:
        if len(self.st) == 0:
            self.st.append((val, val))
        else:
            self.st.append((val, min(val, self.st[-1][1])))

    def pop(self) -> None:
        self.st.pop()

    def top(self) -> int:
        return self.st[-1][0]

    def getMin(self) -> int:
        return self.st[-1][1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()



array에 무엇을 담느냐?

value

가장 작은 값 추적은...

(value, index)

hashmap

double linked list

