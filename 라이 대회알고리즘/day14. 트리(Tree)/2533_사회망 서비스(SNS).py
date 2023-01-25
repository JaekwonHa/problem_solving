import sys

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline


def step1_dfs(edges, visit, DP, current, is_select):
    # base case
    check = False
    for next in edges[current]:
        if not visit[next]:
            check = True
    if not check:
        return is_select

    # memo
    if DP[current][is_select] != -1:
        return DP[current][is_select]

    if is_select == 0:
        answer = 0
        for next in edges[current]:
            if not visit[next]:
                visit[next] = True
                answer += step1_dfs(edges, visit, DP, next, 1)
                visit[next] = False
        DP[current][is_select] = answer
        return answer

    answer = 1
    for next in edges[current]:
        if not visit[next]:
            visit[next] = True
            answer += min(step1_dfs(edges, visit, DP, next, 0), step1_dfs(edges, visit, DP, next, 1))
            visit[next] = False
    DP[current][is_select] = answer
    return answer


if __name__ == '__main__':
    N = int(readline())

    edges = [[] for _ in range(N + 1)]
    root_check = [0 for _ in range(N + 1)]
    for _ in range(N - 1):
        a, b = map(int, readline().split())
        edges[a].append(b)
        edges[b].append(a)
        root_check[a] += 1
        root_check[b] += 1

    start = 0
    for i in range(1, N + 1):
        if root_check[i] == 1:
            start = i
            break

    DP = [[-1 for _ in range(2)] for _ in range(N + 1)]

    visit = [False for _ in range(N + 1)]
    visit[1] = True

    answer = min(step1_dfs(edges, visit, DP, 1, 0), step1_dfs(edges, visit, DP, 1, 1))
    print(answer)
