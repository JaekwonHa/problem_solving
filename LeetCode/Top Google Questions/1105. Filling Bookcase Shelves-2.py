import sys
from typing import List
sys.setrecursionlimit(10 ** 6)


MAX = 1000 * 1000
DP = None

class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        global MAX, DP
        DP = [MAX for _ in range(1001)]

        return self.dfs(books, shelfWidth, 0)


    def dfs(self, books, shelfWidth, current):
        global MAX, DP
        if current == len(books):
            return 0

        if DP[current] != MAX:
            return DP[current]

        base = books[current][1]
        width = books[current][0]

        height_next_level = self.dfs(books, shelfWidth, current+1)
        min_height_after_level = base + height_next_level

        for i in range(current+1, len(books)):
            if shelfWidth < books[i][0] + width:
                break

            width += books[i][0]
            base = max(base, books[i][1])

            height_next_level = self.dfs(books, shelfWidth, i+1)
            min_height_after_level = min(min_height_after_level, base + height_next_level)

        DP[current] = min_height_after_level
        return min_height_after_level

