from typing import List
from heapq import heappush, heappop, heapify

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        heap = []
        for i in range(k):
            heappush(heap, (-nums[i], i))

        answer = [-heap[0][0]]
        for i in range(k, len(nums)):
            heappush(heap, (-nums[i], i))
            while heap[0][1] < i-k+1:
                heappop(heap)
            answer.append(-heap[0][0])

        return answer




