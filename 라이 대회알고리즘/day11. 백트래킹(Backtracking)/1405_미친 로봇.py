import sys

sys.setrecursionlimit(10 ** 6)

readline = sys.stdin.readline

direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]


def step1(visit, T, percentage, x, y, count):
    if T == count:
        return 1

    answer = 0
    for i in range(4):
        if percentage[i] == 0:
            continue
        nx, ny = x + direction[i][0], y + direction[i][1]
        if not visit[nx][ny]:
            visit[nx][ny] = True
            result = step1(visit, T, percentage, nx, ny, count+1)
            answer += (result * percentage[i])/100
            visit[nx][ny] = False
    return answer


if __name__ == '__main__':
    T, E, W, S, N = map(int, readline().split())

    percentage = [
        E,
        W,
        S,
        N
    ]

    visit = [[False for _ in range(T*2+1)] for _ in range(T*2+1)]

    visit[T][T] = True
    answer = step1(visit, T, percentage, T, T, 0)
    # print("{:.9f}".format(st[-1]))
    print(answer)
