import heapq
from queue import PriorityQueue


class MedianFinder:

    def __init__(self):
        self.min_heap = []
        self.median = None
        self.max_heap = []

    def addNum(self, num: int) -> None:
        if self.median is None:
            if len(self.min_heap) > 0 and self.min_heap[0] < num:
                self.median = heapq.heappop(self.min_heap)
                heapq.heappush(self.min_heap, num)
            elif len(self.max_heap) > 0 and -self.max_heap[0] > num:
                self.median = -heapq.heappop(self.max_heap)
                heapq.heappush(self.max_heap, -num)
            else:
                self.median = num
        else:
            if self.median < num:
                heapq.heappush(self.min_heap, num)
                heapq.heappush(self.max_heap, -self.median)
            else:
                heapq.heappush(self.min_heap, self.median)
                heapq.heappush(self.max_heap, -num)
            self.median = None

    def findMedian(self) -> float:
        if self.median is None:
            if len(self.min_heap) == 0:
                return self.max_heap[0]
            elif len(self.max_heap) == 0:
                return self.min_heap[0]
            else:
                return (self.min_heap[0] + (-self.max_heap[0])) / 2.0
        else:
            return self.median

# Your MedianFinder object will be instantiated and called as such:
obj = MedianFinder()
obj.addNum(1)
obj.addNum(2)
print(obj.findMedian())
obj.addNum(3)
print(obj.findMedian())
