import math
from collections import defaultdict
from typing import List


class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        edges = defaultdict(list)

        for i in range(len(bombs)):
            for j in range(len(bombs)):
                x1, y1, r1 = bombs[i][0], bombs[i][1], bombs[i][2]
                x2, y2, r2 = bombs[j][0], bombs[j][1], bombs[j][2]

                # 두 원의 거리
                distance = math.sqrt((x1-x2)**2 + (y1-y2)**2)

                if distance == 0 and r1 == r2:
                    # 두 원이 동심원
                    edges[i].append(j)
                    edges[j].append(i)
                elif r1 + r2 == distance:
                    # 두 원이 외접
                    continue
                elif abs(r1-r2) == distance:
                    # 두 원이 내접
                    edges[i].append(j)
                    edges[j].append(i)
                elif abs(r1-r2) < distance < r1+r2:
                    # 두 원이 서로 다른 두 점에서 만남
                    edges[i].append(j)
                    edges[j].append(i)

                # 두 원의 관계로 생각하지 말고..한 점이 원 내부에 존재하는지를 확인하자. 이게 더 간단하다
                if i == j: continue
                distance = math.sqrt((x1-x2)**2 + (y1-y2)**2)
                if distance <= r1:
                    edges[i].append(j)

        answer = 0
        for i in range(len(bombs)):
            visit = [False for _ in range(len(bombs))]
            visit[i] = True
            answer = max(answer, self.dfs(edges, visit, i))
        return answer

    def dfs(self, edges, visit, current):
        result = 1

        for next in edges[current]:
            if not visit[next]:
                visit[next] = True
                result += self.dfs(edges, visit, next)
        return result

s = Solution()
bombs = [[1,1,5],[10,10,5]]
print(s.maximumDetonation(bombs))

bombs = [[2,1,3],[6,1,4]]
print(s.maximumDetonation(bombs))

