import sys

readline = sys.stdin.readline

sys.setrecursionlimit(10 ** 6)

adj = None
visit = [False] * 1001
finish = [False] * 1001

cycle_count = 0
component_count = 0

item = []


def step1(u):
    global cycle_count, component_count
    visit[u] = True
    component_count += 1

    v = adj[u]
    if visit[v] == True and finish[v] == False:
        temp = v
        while u != temp:
            cycle_count += 1
            temp = adj[temp]
        cycle_count += 1
    else:
        if visit[v] == False:
            step1(v)
    finish[u] = True
    return


if __name__ == '__main__':
    N, K = map(int, readline().split())

    adj = [0, *[int(i) for i in readline().split()]]
    item.append((0, 0))

    for i in range(1, N + 1):
        cycle_count = 0
        component_count = 0
        if visit[i] == False:
            step1(i)
            if cycle_count != 0:
                item.append((cycle_count, component_count))

    # k = 0
    # answer.sort(reverse=True)
    # for a in answer:
    #     if k + a <= K:
    #         k += a
    #
    # print(k)

    # print(answer)
    cache = [[0 for _ in range(K + 1)] for _ in range(len(item))]
    for i in range(1, len(item)):
        for j in range(K + 1):
            for weight in range(item[i][0], item[i][1] + 1):
                if j - weight < 0:
                    cache[i][j] = max(cache[i][j], cache[i - 1][j])
                else:
                    cache[i][j] = max(cache[i][j], cache[i - 1][j], weight + cache[i - 1][j - weight])

    print(cache[len(item) - 1][K])
