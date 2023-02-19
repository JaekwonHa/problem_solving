import heapq
from collections import OrderedDict


class StockPrice:

    def __init__(self):
        self.hash = OrderedDict()
        self.max_heap = []
        self.min_heap = []
        self.last_timestamp = -1

    def update(self, timestamp: int, price: int) -> None:
        self.last_timestamp = max(self.last_timestamp, timestamp)

        self.hash[timestamp] = price
        heapq.heappush(self.max_heap, (-price, timestamp))
        heapq.heappush(self.min_heap, (price, timestamp))

        while self.max_heap and self.hash[self.max_heap[0][1]] != -self.max_heap[0][0]:
            heapq.heappop(self.max_heap)
        while self.min_heap and self.hash[self.min_heap[0][1]] != self.min_heap[0][0]:
            heapq.heappop(self.min_heap)


    def current(self) -> int:
        # keys = self.hash.keys()
        # return self.hash[keys[-1]]
        return self.hash[self.last_timestamp]

    def maximum(self) -> int:
        return -self.max_heap[0][0]

    def minimum(self) -> int:
        return self.min_heap[0][0]

# Your StockPrice object will be instantiated and called as such:
obj = StockPrice()
obj.update(1, 10)
obj.update(2, 5)
obj.update(1, 3)
obj.update(4, 2)
param_2 = obj.current()
param_3 = obj.maximum()
param_4 = obj.minimum()