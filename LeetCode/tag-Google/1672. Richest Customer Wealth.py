from typing import List


class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return sum(max(accounts, key = lambda x: sum(x)))
