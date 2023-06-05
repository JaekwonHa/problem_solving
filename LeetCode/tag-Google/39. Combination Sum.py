from typing import List


class Solution:
    answer = []
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.answer = []
        self.backtracking(candidates, 0, [], target)
        return self.answer

    def backtracking(self, candidates: List[int], i: int, select: List, remain: int):
        if remain < 0 or i >= len(candidates):
            return

        if remain == 0:
            self.answer.append(select.copy())
            return

        self.backtracking(candidates, i + 1, select, remain)

        select.append(candidates[i])
        self.backtracking(candidates, i, select, remain - candidates[i])
        select.pop()


s = Solution()

print(s.combinationSum([2,3,6,7], 7))
