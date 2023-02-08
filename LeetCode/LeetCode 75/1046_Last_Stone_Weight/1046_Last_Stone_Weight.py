from typing import *
from heapq import heappush, heappop, heapify

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = []
        for stone in stones:
            heappush(heap, (-stone, stone))

        # heapify(heap)
        while len(heap) > 1:
            one, two = heappop(heap)[1], heappop(heap)[1]
            if one != two:
                heappush(heap, (-(one-two), one-two))

        if len(heap) == 0:
            return 0
        else:
            return heap[0][1]
        

s = Solution()

print(s.lastStoneWeight([2,7,4,1,8,1]))
print(s.lastStoneWeight([1]))



