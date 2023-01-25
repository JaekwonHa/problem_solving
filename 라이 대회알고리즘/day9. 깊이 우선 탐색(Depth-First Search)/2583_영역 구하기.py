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
            if board[x + dx][y + dy] == 0 and visit[x + dx][y + dy] == False:
                answer += step1(M, N, x + dx, y + dy)

    return answer


if __name__ == '__main__':
    M, N, K = map(int, readline().split())

    board = [[0 for _ in range(N)] for _ in range(M)]
    visit = [[False for _ in range(N)] for _ in range(M)]

    for _ in range(K):
        x0, y0, x1, y1 = map(int, readline().split())
        for i in range(y0, y1):
            for j in range(x0, x1):
                board[i][j] = 1

    answer = []
    for x in range(M):
        for y in range(N):
            if board[x][y] == 0 and visit[x][y] == False:
                answer.append(step1(M, N, x, y))

    answer.sort()
    print(len(answer))
    print(" ".join(list(map(str, answer))))
