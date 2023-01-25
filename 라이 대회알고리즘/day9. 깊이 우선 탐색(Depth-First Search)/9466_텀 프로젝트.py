import sys
readline=sys.stdin.readline

sys.setrecursionlimit(10**6)

adj = None
visit = [False] * 100001
finish = [False] * 100001
cycle_count = 0


def step1(u):
    visit[u] = True

    v = adj[u]
    if v == -1:
        finish[u] = True
        return

    global cycle_count
    if visit[v] == True and finish[v] == False:
        cycle_count += 1
        temp = v
        while u != temp:
            cycle_count += 1
            temp = adj[temp]
    else:
        if visit[v] == False:
            step1(v)
    finish[u] = True
    return


if __name__ == '__main__':
    T = int(readline())

    for _ in range(T):
        N = int(readline())
        text = list(map(int, readline().replace('\n', '').split()))
        adj = [-1 for _ in range(0, N+1)]
        visit = [False] * 100001
        finish = [False] * 100001
        for i in range(1, N+1):
            adj[i] = text[i-1]

        cycle_count = 0
        for i in range(1, N+1):
            if visit[i] == False:
                step1(i)

        print(N - cycle_count)

