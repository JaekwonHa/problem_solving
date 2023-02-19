from collections import defaultdict, deque
from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        visit = [False for _ in range(numCourses)]
        edges = [[] for _ in range(numCourses)]
        indegree_map = defaultdict(int)

        for i in range(len(prerequisites)):
            end = prerequisites[i][0]
            start = prerequisites[i][1]
            edges[start].append(end)
            indegree_map[end] += 1

        answer = []
        q = deque([])
        for i in range(numCourses):
            if indegree_map[i] == 0 and visit[i] is False:
                visit[i] = True
                q.append(i)

        while len(q) > 0:
            current = q.popleft()
            answer.append(current)

            for i in range(len(edges[current])):
                next = edges[current][i]
                indegree_map[next] -= 1
                if indegree_map[next] <= 0 and visit[next] is False:
                    visit[next] = True
                    q.append(next)

        return answer if len(answer) == numCourses else []


s = Solution()
numCourses = 2
prerequisites = [[1,0]]
print(s.findOrder(numCourses, prerequisites))

numCourses = 4
prerequisites = [[1,0],[2,0],[3,1],[3,2]]
print(s.findOrder(numCourses, prerequisites))

numCourses = 1
prerequisites = []
print(s.findOrder(numCourses, prerequisites))

numCourses = 3
prerequisites = [[0,1],[0,2],[1,2]]
print(s.findOrder(numCourses, prerequisites))

numCourses = 3
prerequisites = []
print(s.findOrder(numCourses, prerequisites))

numCourses = 7
prerequisites = [[1,0],[0,3],[0,2],[3,2],[2,5],[4,5],[5,6],[2,4]]
print(s.findOrder(numCourses, prerequisites))
