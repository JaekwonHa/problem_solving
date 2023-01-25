import sys

readline = sys.stdin.readline


def step1_dfs(N, board, P, DP, visit, used, count, idx):
    if P <= count:
        return 0

    if DP[idx][visit] != -1:
        return DP[idx][visit]

    answer = int(1e9)
    for i, weight in enumerate(board[idx]):
        if idx == i:
            continue
        if visit & (1 << i) == 0:
            visit |= (1 << i)
            if used & (1 << i) == 0:
                used |= (1 << i)
                answer = min(answer, step1_dfs(N, board, P, DP, visit, used, count + 1, idx) + weight)
                answer = min(answer, step1_dfs(N, board, P, DP, visit, used, count + 1, i) + weight)
                used &= ~(1 << i)
            else:
                answer = min(answer, step1_dfs(N, board, P, DP, visit, used, count, idx))
                answer = min(answer, step1_dfs(N, board, P, DP, visit, used, count, i))
            visit &= ~(1 << i)
    DP[idx][visit] = answer
    return answer


def step1():
    N = int(readline())
    board = [list(map(int, readline().split())) for _ in range(N)]
    active = readline().replace('\n', '')
    P = int(readline())

    DP = [[-1 for _ in range(1 << N)] for _ in range(N)]

    start = -1
    count = 0
    used = 0
    for i, c in enumerate(active):
        if c == 'Y':
            start = i
            count += 1
            used |= (1 << i)

    if start == -1:
        print(-1)
    else:
        visit = (1 << start)
        answer = step1_dfs(N, board, P, DP, visit, used, count, start)
        if answer == int(1e9):
            print(-1)
        else:
            print(answer)


def step2_dfs(board, N, P, DP, used, count):
    if P <= count:
        return 0

    if DP[used] != -1:
        return DP[used]

    answer = int(1e9)
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            if used & (1 << i) != 0 and used & (1 << j) == 0:
                used |= (1 << j)
                answer = min(answer, step2_dfs(board, N, P, DP, used, count+1)+board[i][j])
                used &= ~(1 << j)
    DP[used] = answer
    return answer


def step2():
    N = int(readline())
    board = [list(map(int, readline().split())) for _ in range(N)]
    active = readline().replace('\n', '')
    P = int(readline())

    DP = [-1 for _ in range(1 << N)]
    used = 0
    count = 0
    for i in range(len(active)):
        if active[i] == 'Y':
            used |= (1 << i)
            count += 1

    answer = step2_dfs(board, N, P, DP, used, count)
    if answer == int(1e9):
        print(-1)
    else:
        print(answer)


if __name__ == '__main__':
    # step1()
    step2()
