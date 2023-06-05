from typing import List
import sys
sys.setrecursionlimit(10**6)

direction = [
    (1, 0),
    (0, 1),
    (-1, 0),
    (0, -1)
]

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        X, Y = len(grid), len(grid[0])
        visit = [[False for _ in range(Y)] for _ in range(X)]

        answer = 0
        for x in range(X):
            for y in range(Y):
                if grid[x][y] == 0 and not visit[x][y]:
                    visit[x][y] = True
                    result = self.dfs(x, y, visit, grid)
                    if result:
                        answer += 1

        return answer

    def dfs(self, x, y, grid: List[List[int]], visit: List[List[bool]]) -> bool:
        X, Y = len(grid), len(grid[0])

        result = True
        for dx, dy in direction:
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= X or ny < 0 or ny >= Y:
                result = False
            elif grid[nx][ny] == 0 and not visit[nx][ny]:
                visit[nx][ny] = True
                result &= self.dfs(nx, ny, visit, grid)

        return result
