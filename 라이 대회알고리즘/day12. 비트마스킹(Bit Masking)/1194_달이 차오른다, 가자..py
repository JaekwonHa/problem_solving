import sys
from collections import deque

readline = sys.stdin.readline

direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]

if __name__ == '__main__':
    N, M = map(int, readline().split())
    board = [readline().replace('\n', '') for _ in range(N)]

    visit = [[[False for _ in range(1 << 6)] for _ in range(M)] for _ in range(N)]
    q = deque([])
    for x in range(N):
        for y in range(M):
            if board[x][y] == '0':
                visit[x][y][0] = True
                q.append((x, y, 0))

    level = 0
    while len(q) != 0:
        q_size = len(q)
        for _ in range(q_size):
            x, y, keys = q.popleft()

            if board[x][y] == '1':
                print(level)
                exit(0)

            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 0 <= nx < N and 0 <= ny < M and board[nx][ny] != '#':
                    next_keys = keys
                    if board[nx][ny] in ['a', 'b', 'c', 'd', 'e', 'f']:
                        next_keys |= (1 << (ord(board[nx][ny]) - ord('a')))
                    if not visit[nx][ny][next_keys]:
                        if board[nx][ny] in ['A', 'B', 'C', 'D', 'E', 'F']:
                            if next_keys & (1 << (ord(board[nx][ny]) - ord('A'))):
                                visit[nx][ny][next_keys] = True
                                q.append((nx, ny, next_keys))
                        else:
                            visit[nx][ny][next_keys] = True
                            q.append((nx, ny, next_keys))
        level += 1
    print(-1)
