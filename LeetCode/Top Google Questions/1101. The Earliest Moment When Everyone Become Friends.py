from typing import List


class Solution:
    def __init__(self):
        self.sortedLogs = []
        self.p = []

    def find(self, x):
        if self.p[x] < 0:
            return x

        parent = self.find(self.p[x])
        self.p[x] = parent
        return parent

    def union(self, x, y) -> int:
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return self.p[x]

        self.p[x] += self.p[y]
        self.p[y] = x
        return self.p[x]

    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        self.sortedLogs = sorted(logs, key=lambda x: x[0])
        self.p = [-1 for _ in range(n)]

        for log in self.sortedLogs:
            timestamp, x, y = log[0], log[1], log[2]
            answer = self.union(x, y)
            if -answer == n:
                return timestamp
        return -1

s = Solution()
logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]]
n = 4

print(s.earliestAcq(logs, n))
