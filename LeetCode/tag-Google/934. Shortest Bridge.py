from typing import List
from collections import deque
import sys
sys.setrecursionlimit(10**6)

direction = [
    (0, 1),
    (1, 0),
    (0, -1),
    (-1, 0)
]


class Solution:
    def __init__(self):
        self.answer = None

    def markIsland(self, grid, color, x, y):
        grid[x][y] = color
        for dx, dy in direction:
            nx, ny = x + dx, y + dy
            if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 1:
                self.markIsland(grid, color, nx, ny)

    # DFS 방식으론 TLE, BFS 방식으로 ACCEPT
    # def dfs(self, grid, visit, x, y, count):
    #     if self.answer <= count:
    #         return
    #
    #     for dx, dy in direction:
    #         nx, ny = x + dx, y + dy
    #         if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and not visit[nx][ny]:
    #             if grid[nx][ny] == 0:
    #                 visit[nx][ny] = True
    #                 self.dfs(grid, visit, nx, ny, count + 1)
    #                 visit[nx][ny] = False
    #             elif grid[nx][ny] == 3:
    #                 self.answer = min(self.answer, count)
    #
    # def shortestBridge(self, grid: List[List[int]]) -> int:
    #     color = 2
    #     for x in range(len(grid)):
    #         for y in range(len(grid[0])):
    #             if grid[x][y] == 1:
    #                 self.markIsland(grid, color, x, y)
    #                 color = 3
    #
    #     self.answer = 987654321
    #     visit = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
    #     for x in range(len(grid)):
    #         for y in range(len(grid[0])):
    #             if grid[x][y] == 2:
    #                 self.dfs(grid, visit, x, y, 0)
    #
    #     return self.answer

    def shortestBridge(self, grid: List[List[int]]) -> int:
        color = 2
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] == 1:
                    self.markIsland(grid, color, x, y)
                    color = 3

        q = deque([])
        visit = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]

        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] == 2:
                    q.append((x, y))

        step = 0
        while len(q) != 0:
            q_size = len(q)
            for _ in range(q_size):
                x, y = q.popleft()
                for dx, dy in direction:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and not visit[nx][ny]:
                        if grid[nx][ny] == 0:
                            visit[nx][ny] = True
                            q.append((nx, ny))
                        if grid[nx][ny] == 3:
                            return step
            step += 1




s = Solution()

grid = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 1, 1, 1, 1, 0, 0, 1, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
        [0, 1, 1, 1, 1, 1, 1, 1, 1, 0],
        [1, 0, 1, 1, 1, 1, 1, 1, 1, 0],
        [1, 1, 0, 1, 1, 1, 1, 1, 1, 1]]
print(s.shortestBridge(grid))
