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


def step1(N, M, x, y):
    visit[x][y] = True

    for dx, dy in direction:
        if 0 <= x+dx < M and 0 <= y+dy < N:
            if board[x+dx][y+dy] == 1 and visit[x+dx][y+dy] == False:
                step1(N, M, x+dx, y+dy)


if __name__ == '__main__':
    T = int(readline())

    for _ in range(T):
        M, N, K = map(int, readline().split())

        board = [[0 for _ in range(N)] for _ in range(M)]
        visit = [[False for _ in range(N)] for _ in range(M)]

        for _ in range(K):
            x, y = map(int, readline().split())
            board[x][y] = 1

        answer = 0
        for i in range(M):
            for j in range(N):
                if board[i][j] == 1 and visit[i][j] == False:
                    step1(N, M, i, j)
                    answer += 1

        print(answer)
