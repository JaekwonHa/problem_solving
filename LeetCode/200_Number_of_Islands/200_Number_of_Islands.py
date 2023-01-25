dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def safe(m, n, x, y):
    return 0<=x<m and 0<=y<n

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        color = 0
        m = []
        visit: List[List[bool]] = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]

        for i, x in enumerate(grid):
            for j, y in enumerate(x):
                if y == '1' and visit[i][j] == False:
                    color += 1
                    m.append((i,j))
                    while len(m) != 0:
                        (xx, yy) = m.pop(0)
                        if visit[xx][yy] == True:
                            continue
                        visit[xx][yy] = True
                        for ii in range(4):
                            next_x, next_y = xx+dx[ii], yy+dy[ii]
                            if safe(len(grid), len(grid[0]), next_x, next_y) and grid[next_x][next_y] == '1' and visit[next_x][next_y] == False:
                                m.append((next_x, next_y))

        return color

