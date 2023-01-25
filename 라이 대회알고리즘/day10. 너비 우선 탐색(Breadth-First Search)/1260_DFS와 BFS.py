import sys
from collections import deque

readline = sys.stdin.readline


def dfs(N, adj, visit, v):
    visit[v] = True

    answer = [v]
    for next in adj[v]:
        if visit[next] == False:
            answer.extend(dfs(N, adj, visit, next))

    return answer


def bfs(N, adj, visit, v):
    q = deque([])

    visit[v] = True
    q.append(v)

    answer = []
    while len(q) != 0:
        current = q.popleft()
        answer.append(current)
        for next in adj[current]:
            if visit[next] == False:
                visit[next] = True
                q.append(next)
    return answer


if __name__ == '__main__':
    N, M, V = map(int, readline().split())

    adj = [[] for _ in range(N + 1)]

    for _ in range(M):
        a, b = map(int, readline().split())
        adj[a].append(b)
        adj[b].append(a)

    for i in range(N+1):
        adj[i].sort()

    visit = [False] * (N + 1)
    print(" ".join(list(map(str, dfs(N, adj, visit, V)))))
    visit = [False] * (N + 1)
    print(" ".join(list(map(str, bfs(N, adj, visit, V)))))
