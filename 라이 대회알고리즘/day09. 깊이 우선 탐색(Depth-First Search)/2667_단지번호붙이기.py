import sys

readline = sys.stdin.readline

sys.setrecursionlimit(10 ** 6)

board = None
visit = None

direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]


def step1(N, x, y):
    visit[x][y] = True

    answer = 1
    for dx, dy in direction:
        if 0 <= x + dx < N and 0 <= y + dy < N:
            if board[x + dx][y + dy] == '1' and visit[x + dx][y + dy] == False:
                answer += step1(N, x + dx, y + dy)

    return answer


if __name__ == '__main__':
    N = int(readline())

    board = [readline().replace('\n', '') for _ in range(N)]
    visit = [[False for _ in range(N)] for _ in range(N)]

    answer = []
    for x in range(N):
        for y in range(N):
            if board[x][y] == '1' and visit[x][y] == False:
                answer.append(step1(N, x, y))

    answer.sort()
    print(len(answer))
    for a in answer:
        print(a)
