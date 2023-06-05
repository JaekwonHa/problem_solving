import heapq
from collections import defaultdict
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hash = defaultdict(int)
        for num in nums:
            hash[num] += 1

        hq = []
        for key, value in hash.items():
            heapq.heappush(hq, (-value, key))

        answer = []
        for i in range(k):
            answer.append(heapq.heappop(hq)[1])

        return answer


s = Solution()

print(s.topKFrequent([1,1,1,2,2,3], 2))

print(s.topKFrequent([-1, -1], 1))
