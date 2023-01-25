import sys
from collections import deque

readline=sys.stdin.readline

direction = [
    (2, 1),
    (1, 2),
    (-2, 1),
    (-1, 2),
    (-1, -2),
    (-2, -1),
    (1, -2),
    (2, -1)
]

if __name__ == '__main__':
    T = int(readline())
    for _ in range(T):
        L = int(readline())
        a, b = map(int, readline().split())
        
        visit = [[False for _ in range(L)] for _ in range(L)]

        q = deque([(a, b)])
        visit[a][b] = True
        
        a, b = map(int, readline().split())
        answer = -1
        while len(q) != 0:
            answer += 1
            q_size = len(q)
            for _ in range(q_size):
                cx, cy = q.popleft()
                if (cx, cy) == (a, b):
                    print(answer)
                    q.clear()
                    break
                for dx, dy in direction:
                    nx, ny = cx + dx, cy + dy
                    if 0 <= nx < L and 0 <= ny < L:
                        if not visit[nx][ny]:
                            visit[nx][ny] = True
                            q.append((nx, ny))
