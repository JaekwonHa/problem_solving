import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline


def find(n: int):
    global p
    if p[n] < 0:
        return n
    p[n] = find(p[n])
    return p[n]


def merge(a: int, b: int):
    global p, cost
    a = find(a)
    b = find(b)
    if a == b:
        return
    if cost[a] < cost[b]:
        p[b] = a
    else:
        p[a] = b


if __name__ == '__main__':
    N, M, K = map(int, readline().split())
    cost = list(map(int, readline().split()))
    cost = [10001, *cost]

    p = [-1 for _ in range(N + 1)]
    for _ in range(M):
        a, b = map(int, readline().split())
        merge(a, b)

    answer = 0
    for i in range(1, N+1):
        if find(0) != find(i):
            answer += cost[find(i)]
            merge(0, i)

    if answer <= K:
        print(answer)
    else:
        print("Oh no")
