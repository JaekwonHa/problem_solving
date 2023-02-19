from collections import defaultdict
from typing import List


class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        indegree_counter = defaultdict(int)

        edges = [[] for _ in range(n+1)]
        for rel in relations:
            prev, next = rel[0], rel[1]
            edges[prev].append(next)
            indegree_counter[next] += 1

        step = 0
        node = 0

        while True:
            check = False
            visit = [False for _ in range(n+1)]
            for i in range(1, n+1):
                if not visit[i] and indegree_counter[i] == 0:
                    for next in edges[i]:
                        visit[next] = True
                        indegree_counter[next] = max(0, indegree_counter[next]-1)
                    indegree_counter[i] = -1
                    node += 1
                    check = True
            if not check:
                break
            step += 1

        return step if node == n else -1

s = Solution()

n = 3
relations = [[1,3],[2,3]]
print(s.minimumSemesters(n, relations))

n = 3
relations = [[1,2],[2,3],[3,1]]
print(s.minimumSemesters(n, relations))
