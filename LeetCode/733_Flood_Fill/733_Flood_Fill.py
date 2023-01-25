from typing import *

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def safe(m, n, x, y):
    return 0<=x<m and 0<=y<n

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if (image[sr][sc] == color):
            return image

        m, n = len(image), len(image[0])
        stack = [(sr, sc)]
        target_color = image[sr][sc]

        flooded_image = image
        cache: List[List[bool]] = [[False for _ in range(n)] for _ in range(m)]

        while len(stack) != 0:
            (r, c) = stack.pop(0)
            if cache[r][c]:
                continue
            cache[r][c] = True
            flooded_image[r][c] = color
            for i in range(4):
                next_x, next_y = r+dx[i], c+dy[i]
                if safe(m, n, next_x, next_y) and flooded_image[next_x][next_y] == target_color:
                    stack.append((next_x, next_y))

        return flooded_image















