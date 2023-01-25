import sys
from collections import deque
sys.setrecursionlimit(10**6)
readline=sys.stdin.readline


answer = 0
deep_node = 0


def step1():
    global answer
    N = int(readline())
    edges = [[] for _ in range(N+1)]

    for _ in range(N-1):
        a, b, c = map(int, readline().split())
        edges[a].append((b, c))

    step1_dfs_postorder(edges, 1)
    print(answer)


def step1_dfs_postorder(edges, current):
    global answer
    if len(edges[current]) == 0:
        return 0

    left, right = 0, 0
    left = step1_dfs_postorder(edges, edges[current][0][0]) + edges[current][0][1]
    if len(edges[current]) == 2:
        right = step1_dfs_postorder(edges, edges[current][1][0]) + edges[current][1][1]

    answer = max(answer, left + right)
    return max(left, right)


def step2():
    global answer, deep_node
    N = int(readline())
    edges = [[] for _ in range(N+1)]

    for _ in range(N-1):
        a, b, c = map(int, readline().split())
        edges[a].append((b, c))
        edges[b].append((a, c))


    visit = [False for _ in range(N+1)]
    step2_dfs_postorder(edges, visit, 1, 0)

    visit = [False for _ in range(N+1)]
    step2_dfs_postorder(edges, visit, deep_node, 0)

    print(answer)


def step2_dfs_postorder(edges, visit, current, depth):
    global answer, deep_node
    visit[current] = True

    if answer < depth:
        answer = depth
        deep_node = current

    if len(edges[current]) == 0:
        return

    for next, cost in edges[current]:
        if not visit[next]:
            step2_dfs_postorder(edges, visit, next, depth + cost)


if __name__ == '__main__':
    step2()
