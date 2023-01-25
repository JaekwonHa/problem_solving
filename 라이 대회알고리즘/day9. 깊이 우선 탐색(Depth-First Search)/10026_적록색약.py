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

color_check = [
    {
        "R": ["R"],
        "G": ["G"],
        "B": ["B"]
    },
    {
        "R": ["R", "G"],
        "G": ["G", "R"],
        "B": ["B"]
    }
]


def step1(M, N, x, y, i, color):
    visit[x][y] = True

    for dx, dy in direction:
        if 0 <= x + dx < M and 0 <= y + dy < N:
            if color in color_check[i][board[x + dx][y + dy]] and visit[x + dx][y + dy] == False:
                step1(M, N, x + dx, y + dy, i, color)


if __name__ == '__main__':
    N = int(readline())

    board = [readline().replace('\n', '') for _ in range(N)]

    for i in range(2):
        visit = [[False for _ in range(N)] for _ in range(N)]
        answer = 0
        for x in range(N):
            for y in range(N):
                if visit[x][y] == False:
                    answer += 1
                    step1(N, N, x, y, i, board[x][y])
        print(answer, end=" ")
