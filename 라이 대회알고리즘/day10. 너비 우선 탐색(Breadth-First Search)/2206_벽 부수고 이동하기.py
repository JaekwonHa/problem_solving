import sys
from collections import deque

readline=sys.stdin.readline

direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]

if __name__ == '__main__':
    N, M = map(int, readline().split())

    board = [readline().replace('\n', '') for _ in range(N)]
    visit = [[[False for _ in range(M)] for _ in range(N)] for _ in range(2)]

    q = deque([(1, 0, 0)])
    visit[1][0][0] = True
    visit[0][0][0] = True

    answer = 0
    while len(q) != 0:
        answer += 1
        q_size = len(q)
        for _ in range(q_size):
            smash, cx, cy = q.popleft()
            if (cx, cy) == (N-1, M-1):
                print(answer)
                exit(0)
            for dx, dy in direction:
                nx, ny = cx + dx, cy + dy
                if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == '0':
                    if not visit[smash][nx][ny]:
                        visit[smash][nx][ny] = True
                        q.append((smash, nx, ny))
                if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == '1' and smash > 0:
                    if not visit[smash-1][nx][ny]:
                        visit[smash-1][nx][ny] = True
                        q.append((smash-1, nx, ny))
    else:
        print(-1)
    
