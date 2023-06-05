from typing import List


class Solution:
    answer = []

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.answer = []
        self.dfs(len(graph), graph, 0, [0])

        return self.answer

    def dfs(self, n, graph, node, path):
        if node == n-1:
            self.answer.append(path)
            return

        for next in graph[node]:
            self.dfs(n, graph, next, [*path, next])
