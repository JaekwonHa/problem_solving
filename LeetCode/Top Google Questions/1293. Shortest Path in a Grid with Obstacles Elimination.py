from collections import deque
from typing import List


class Solution:
    def shortestPath(self, grid: List[List[int]], K: int) -> int:

        # visit = [[[False for _ in range(K + 1)] for _ in range(len(grid[0]))] for _ in range(len(grid))]
        direction = [
            (0, 1),
            (1, 0),
            (0, -1),
            (-1, 0)
        ]
        M, N = len(grid)-1, len(grid[0])-1

        visit = set()
        visit.add((0,0,K))
        q = deque([(0, 0, K)])

        level = -1
        while len(q) > 0:
            level += 1

            q_size = len(q)
            for _ in range(q_size):
                (x, y, k) = q.popleft()

                if x == M and y == N:
                    return level

                for dx, dy in direction:
                    nx, ny = x+dx, y+dy
                    if 0 <= nx <= M and 0 <= ny <= N:
                        if grid[nx][ny] == 0:
                            # if visit[nx][ny][k]:
                            if (nx,ny,k) in visit:
                                continue
                            # visit[nx][ny][k] = True
                            visit.add((nx,ny,k))
                            q.append((nx, ny, k))
                        else:
                            # if k == 0 or visit[nx][ny][k - 1]:
                            if k == 0 or (nx, ny, k-1) in visit:
                                continue
                            # visit[nx][ny][k-1] = True
                            visit.add((nx,ny,k-1))
                            q.append((nx, ny, k-1))
        return -1



s = Solution()
grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]
k = 1
print(s.shortestPath(grid, k))

grid = [[0,1,1],[1,1,1],[1,0,0]]
k = 1
print(s.shortestPath(grid, k))

grid = [[0]]
k = 1
print(s.shortestPath(grid, k))

grid = [[0,0,0]]
k = 1
print(s.shortestPath(grid, k))
