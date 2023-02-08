import sys
readline=sys.stdin.readline

sys.setrecursionlimit(10**6)

node = {}
visit = [False] * 1001


def step1(u):
    visit[u] = True

    for v in node[u]:
        if visit[v] == False:
            step1(v)
    return


if __name__ == '__main__':
    N, M = map(int, readline().split())

    for i in range(1, N+1):
        node[i] = []

    for _ in range(M):
        u, v = map(int, readline().split())
        node[u].append(v)
        node[v].append(u)

    answer = 0
    for i in range(1, N+1):
        if visit[i] == False:
            answer += 1
            step1(i)

    print(answer)
