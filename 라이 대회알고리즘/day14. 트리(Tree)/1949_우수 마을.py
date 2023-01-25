import sys

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline


def step1_dfs(points, edges, visit, DP, current, is_select):
    # base case
    check = False
    for next in edges[current]:
        if not visit[next]:
            check = True
    if not check:
        if is_select == 1:
            return points[current - 1]
        return 0

    # memo
    if DP[current][is_select] != -1:
        return DP[current][is_select]

    # 자신이 우수마을이라면 자식은 무조건 우수마을이 아님
    if is_select == 1:
        answer = points[current - 1]
        for next in edges[current]:
            if not visit[next]:
                visit[next] = True
                answer += step1_dfs(points, edges, visit, DP, next, 0)
                visit[next] = False
        DP[current][is_select] = answer
        return answer

    child_nodes = []
    for next in edges[current]:
        if not visit[next]:
            child_nodes.append(next)

    answer = 0
    if len(child_nodes) == 1:
        # 첫번째 자식만 우수마을로 선정
        visit[child_nodes[0]] = True
        answer = max(answer, step1_dfs(points, edges, visit, DP, child_nodes[0], 1))
        visit[child_nodes[0]] = False

    elif len(child_nodes) == 2:
        local_answer = 0
        # 첫번째 자식만 우수마을로 선정
        visit[child_nodes[0]] = True
        local_answer += step1_dfs(points, edges, visit, DP, child_nodes[0], 1)
        visit[child_nodes[0]] = False
        visit[child_nodes[1]] = True
        local_answer += step1_dfs(points, edges, visit, DP, child_nodes[1], 0)
        visit[child_nodes[1]] = False
        answer = max(answer, local_answer)

        local_answer = 0
        # 두번째 자식만 우수마을로 선정
        visit[child_nodes[0]] = True
        local_answer += step1_dfs(points, edges, visit, DP, child_nodes[0], 0)
        visit[child_nodes[0]] = False
        visit[child_nodes[1]] = True
        local_answer += step1_dfs(points, edges, visit, DP, child_nodes[1], 1)
        visit[child_nodes[1]] = False
        answer = max(answer, local_answer)

        local_answer = 0
        # 자식 모두를 우수마을로 선정
        visit[child_nodes[0]] = True
        local_answer += step1_dfs(points, edges, visit, DP, child_nodes[0], 1)
        visit[child_nodes[0]] = False
        visit[child_nodes[1]] = True
        local_answer += step1_dfs(points, edges, visit, DP, child_nodes[1], 1)
        visit[child_nodes[1]] = False
        answer = max(answer, local_answer)

    DP[current][is_select] = answer
    return answer


def step2_dfs(points, edges, visit, DP, current, is_select):
    # base case
    check = False
    for next in edges[current]:
        if not visit[next]:
            check = True
    if not check:
        if is_select == 1:
            return points[current - 1]
        return 0

    # memo
    if DP[current][is_select] != -1:
        return DP[current][is_select]

    if is_select == 1:
        answer = points[current - 1]
        for next in edges[current]:
            if not visit[next]:
                visit[next] = True
                answer += step2_dfs(points, edges, visit, DP, next, 0)
                visit[next] = False
        DP[current][is_select] = answer
        return answer

    answer = 0
    for next in edges[current]:
        if not visit[next]:
            visit[next] = True
            answer += max(step2_dfs(points, edges, visit, DP, next, 0), step2_dfs(points, edges, visit, DP, next, 1))
            visit[next] = False
    DP[current][is_select] = answer
    return answer


if __name__ == '__main__':
    N = int(readline())
    points = list(map(int, readline().split()))

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
    visit[start] = True

    answer = 0
    answer = max(answer, step2_dfs(points, edges, visit, DP, start, 0))
    answer = max(answer, step2_dfs(points, edges, visit, DP, start, 1))

    print(answer)
