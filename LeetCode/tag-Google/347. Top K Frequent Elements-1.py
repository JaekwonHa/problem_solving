from collections import defaultdict
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hash = defaultdict(int)
        for num in nums:
            hash[num] += 1

        # hash2 = {}
        # for key, value in hash.items():
        #     hash2[] = key

        return list(map(lambda x: x[0], sorted(list(hash.items()), key = lambda x: x[1], reverse=True)[:k]))


s = Solution()

print(s.topKFrequent([1,1,1,2,2,3], 2))

print(s.topKFrequent([-1, -1], 1))
