import sys
from collections import deque

readline = sys.stdin.readline

if __name__ == '__main__':

    while True:
        L, R, C = map(int, readline().split())
        if L == R == C == 0:
            break
        building = [[] for _ in range(L)]
        start, end = (0, 0, 0), (0, 0, 0)
        for z in range(L):
            for x in range(R):
                row = readline().replace('\n', '')
                building[z].append(row)
                if 'S' in row:
                    y = row.index('S')
                    start = (z, x, y)
                if 'E' in row:
                    y = row.index('E')
                    end = (z, x, y)
            readline()

        visit = [[[False for _ in range(C)] for _ in range(R)] for _ in range(L)]
        minute = -1
        q = deque([start])
        visit[start[0]][start[1]][start[2]] = True

        direction = [
            (1, 0, 0),
            (-1, 0, 0),
            (0, 1, 0),
            (0, -1, 0),
            (0, 0, 1),
            (0, 0, -1),
        ]

        check = False
        while len(q) != 0:
            minute += 1
            q_size = len(q)
            for _ in range(q_size):
                if end == q[0]:
                    check = True
                    break
                cz, cx, cy = q.popleft()
                for dz, dx, dy in direction:
                    nz, nx, ny = cz + dz, cx + dx, cy + dy
                    if 0 <= nz < L and 0 <= nx < R and 0 <= ny < C:
                        if building[nz][nx][ny] == '#':
                            continue
                        if visit[nz][nx][ny]:
                            continue
                        visit[nz][nx][ny] = True
                        q.append((nz, nx, ny))
            if check:
                print(f"Escaped in {minute} minute(s).")
                break
        else:
            print("Trapped!")
