import sys
from collections import deque
readline=sys.stdin.readline


if __name__ == '__main__':
    N = int(readline())

    tree = {}
    for _ in range(N-1):
        a, b = map(int, readline().split())
        tree.setdefault(b, [])
        tree[b].append(a)
        tree.setdefault(a, [])
        tree[a].append(b)

    answer = [0 for _ in range(N+1)]
    q = deque([1])
    visit = [False for _ in range(N+1)]
    visit[1] = True
    while len(q) != 0:
        current = q.popleft()
        if tree.get(current) is not None:
            for next in tree[current]:
                if not visit[next]:
                    answer[next] = current
                    visit[next] = True
                    q.append(next)

    for i in range(2, N+1):
        print(answer[i])
