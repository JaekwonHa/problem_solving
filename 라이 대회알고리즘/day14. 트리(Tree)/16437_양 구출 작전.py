import sys
from collections import deque
readline=sys.stdin.readline
sys.setrecursionlimit(10**6)


def step1():
    N = int(readline())
    edges = [[] for _ in range(N+1)]
    wolf = [0 for _ in range(N+1)]
    q = deque([])

    for i in range(2, N+1):
        t, a, p = readline().split()

        if t == 'W':
            wolf[i] = int(a)
        else:
            q.append((i, int(a)))
        edges[i].append(int(p))

    answer = 0
    while len(q) != 0:
        current, count = q.popleft()
        if current == 1:
            answer += count
            continue
        for next in edges[current]:
            wolf_count = min(wolf[next], count)
            wolf[next] -= wolf_count
            count -= wolf_count
            q.append((next, count))
    print(answer)


wolf = None
sheep = None


def step2():
    global wolf, sheep
    N = int(readline())
    wolf = [0 for _ in range(N+1)]
    sheep = [0 for _ in range(N+1)]
    edges = [[] for _ in range(N+1)]

    for i in range(2, N+1):
        t, a, p = readline().split()

        if t == 'W':
            wolf[i] = int(a)
        else:
            sheep[i] = int(a)
        edges[int(p)].append(i)

    return step2_dfs(edges, 1)


def step2_dfs(edges, current):
    global wolf, sheep
    if len(edges[current]) == 0:
        result = sheep[current]
        sheep[current] = 0
        return result

    result = 0
    for next in edges[current]:
        result += step2_dfs(edges, next)

    if wolf[current] > 0:
        temp = min(wolf[current], result)
        result -= temp
        wolf[current] -= temp
    if sheep[current] > 0:
        result += sheep[current]
        sheep[current] = 0

    return result


if __name__ == '__main__':
    print(step2())
