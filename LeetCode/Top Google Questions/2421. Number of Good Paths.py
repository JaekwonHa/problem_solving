from collections import defaultdict
from typing import List


class UnionFind:
    def __init__(self, n: int):
        self.p = [-1 for _ in range(n)]

    def find(self, x) -> int:
        if self.p[x] < 0:
            return x
        parent = self.find(self.p[x])
        self.p[x] = parent
        return parent

    def union(self, x, y):
        if x > y:
            x, y = y, x

        x = self.find(x)
        y = self.find(y)

        if x == y:
            return False

        self.p[x] += self.p[y]
        self.p[y] = x
        return True


class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        for edge in edges:
            a, b = edge[0], edge[1]
            adj[a].append(b)
            adj[b].append(a)

        valueToNodeCount = defaultdict(list)
        for i in range(len(vals)):
            valueToNodeCount[vals[i]].append(i)

        uf = UnionFind(len(vals))
        answer = 0
        for value in sorted(valueToNodeCount.keys()):
            for node in valueToNodeCount[value]:
                for neighbor in adj[node]:
                    if value < vals[neighbor]:
                        continue
                    uf.union(node, neighbor)

            group = defaultdict(int)
            for node in valueToNodeCount[value]:
                group[uf.find(node)] += 1

            for count in group.values():
                answer += count * (count+1) // 2

        return answer

s = Solution()
vals = [1,3,2,1,3]
edges = [[0,1],[0,2],[2,3],[2,4]]
print(s.numberOfGoodPaths(vals, edges))

vals = [1,1,2,2,3]
edges = [[0,1],[1,2],[2,3],[2,4]]
print(s.numberOfGoodPaths(vals, edges))

vals = [1]
edges = []
print(s.numberOfGoodPaths(vals, edges))




