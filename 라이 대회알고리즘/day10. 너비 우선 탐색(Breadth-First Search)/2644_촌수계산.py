import sys
from collections import deque

readline = sys.stdin.readline

if __name__ == '__main__':
    N = int(readline())
    start, end = map(int, readline().split())
    M = int(readline())
    adj = [[] for _ in range(N + 1)]
    for _ in range(M):
        x, y = map(int, readline().split())
        adj[x].append(y)
        adj[y].append(x)

    visit = [False] * (N + 1)
    level = -1
    q = deque([start])
    visit[start] = True
    while len(q) != 0:
        level += 1
        q_size = len(q)
        for _ in range(q_size):
            current = q.popleft()
            if current == end:
                print(level)
                exit(0)
            for next in adj[current]:
                if visit[next] == True:
                    continue
                visit[next] = True
                q.append(next)

    print(-1)
