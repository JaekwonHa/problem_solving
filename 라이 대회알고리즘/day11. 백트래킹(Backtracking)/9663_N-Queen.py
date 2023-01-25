import sys

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline

direction = [
    (0, 1),
    # (0, -1),
    (1, 0),
    # (-1, 0)
]


def step1(N, queens, row):
    if row == N and len(queens) == N:
        return 1

    answer = 0
    for col in range(N):
        nx, ny = row, col

        valid = True
        for queen_x, queen_y in queens:
            if queen_y == ny or queen_x + queen_y == nx + ny or queen_x - queen_y == nx - ny:
                valid = False
                break
        if valid:
            queens.append((nx, ny))
            answer += step1(N, queens, row + 1)
            queens.pop()

    return answer


def step2(N):
    q = set()
    q.add((0, ''))
    answer = 0
    while len(q) != 0:
        row, queens = q.pop()
        queens = queens.split('|') if len(queens) != 0 else []
        if len(queens) == N:
            answer += 1
            continue

        for col in range(N):
            nx, ny = row, col
            col_valid = True
            for queen in queens:
                queen_x, queen_y = map(int, queen.split(","))
                if queen_y == ny or queen_x + queen_y == nx + ny or queen_x - queen_y == nx - ny:
                    col_valid = False
                    break
            if col_valid:
                queens.append(f'{nx},{ny}')
                q.add((row+1, '|'.join(queens)))
                queens.pop()
    return answer


if __name__ == '__main__':
    N = int(readline())

    print(step1(N, [], 0))
    # print(step2(N))
