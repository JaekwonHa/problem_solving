from typing import List
from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hash = defaultdict(int)
        for num in nums:
            hash[num] += 1

        answer = sorted(hash.items(), key=lambda item: item[1], reverse=True)
        return [item[0] for item in answer[:k]]

s = Solution()

nums = [1, 1, 1, 2, 2, 3]
k = 2
print(s.topKFrequent(nums, k))
