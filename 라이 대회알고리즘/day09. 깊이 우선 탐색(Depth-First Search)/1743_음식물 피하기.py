import sys
readline=sys.stdin.readline

sys.setrecursionlimit(10**6)

board = None
visit = None


direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]


def step1(M, N, x, y):
    visit[x][y] = True

    answer = 1
    for dx, dy in direction:
        if 0 <= x + dx < M and 0 <= y + dy < N:
            if board[x + dx][y + dy] == 1 and visit[x + dx][y + dy] == False:
                answer += step1(M, N, x + dx, y + dy)

    return answer


if __name__ == '__main__':
    M, N, K = map(int, readline().split())

    board = [[0 for _ in range(N)] for _ in range(M)]
    visit = [[False for _ in range(N)] for _ in range(M)]

    for _ in range(K):
        x, y = map(int, readline().split())
        board[x-1][y-1] = 1

    answer = 0
    for x in range(M):
        for y in range(N):
            if board[x][y] == 1 and visit[x][y] == False:
                answer = max(answer, step1(M, N, x, y))

    print(answer)
