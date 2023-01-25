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


def step1(N, M, x, y, k):
    visit[x][y] = True

    for dx, dy in direction:
        if 0 <= x+dx < M and 0 <= y+dy < N:
            if board[x+dx][y+dy] > k and visit[x+dx][y+dy] == False:
                step1(N, M, x+dx, y+dy, k)


if __name__ == '__main__':

    N = int(readline())

    board = [list(map(int, readline().replace('\n', '').split())) for _ in range(N)]
    K = 1
    for row in board:
        K = max(K, max(row))

    answer = 1
    for k in range(1, K):
        result = 0
        visit = [[False for _ in range(N)] for _ in range(N)]
        for i in range(N):
            for j in range(N):
                if board[i][j] > k and visit[i][j] == False:
                    step1(N, N, i, j, k)
                    result += 1
        answer = max(answer, result)

    print(answer)
