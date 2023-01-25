import sys

sys.setrecursionlimit(10 ** 6)

readline = sys.stdin.readline

direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]


def step1(board, visit, x, y, k):
    global R, C, K
    if x == 0 and y == C - 1 and k == K:
        return 1

    if k >= K:
        return 0

    answer = 0
    for dx, dy in direction:
        nx, ny = x + dx, y + dy
        if 0 <= nx < R and 0 <= ny < C and board[nx][ny] != 'T' and not visit[nx][ny]:
            visit[nx][ny] = True
            answer += step1(board, visit, nx, ny, k+1)
            visit[nx][ny] = False
    return answer


if __name__ == '__main__':
    R, C, K = map(int, readline().split())

    board = [readline().replace('\n', '') for _ in range(R)]
    visit = [[False for _ in range(C)] for _ in range(R)]

    visit[R-1][0] = True
    print(step1(board, visit, R - 1, 0, 1))
