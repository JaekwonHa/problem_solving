from collections import defaultdict
from typing import List
import sys


sys.setrecursionlimit(10**6)


class Solution:
    answer = []

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.answer = []
        for next in nums:
            visit = [next]
            self.dfs(len(nums), nums, visit)

        return self.answer

    def dfs(self, n, nums, visit):
        if len(visit) == n:
            self.answer.append(visit.copy())
            return

        for next in nums:
            if next in visit:
                continue
            visit.append(next)
            self.dfs(n, nums, visit)
            visit.pop()


s = Solution()

input = [1,2,3]
print(s.permute(input))
