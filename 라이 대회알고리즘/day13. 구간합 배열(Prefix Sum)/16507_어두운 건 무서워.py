import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    R, C, Q = map(int, readline().split())

    board = [list(map(int, readline().split())) for _ in range(R)]

    prefix_sum = [[0 for _ in range(C+1)] for _ in range(R+1)]

    for x in range(1, R+1):
        for y in range(1, C+1):
            prefix_sum[x][y] = board[x-1][y-1] + prefix_sum[x-1][y] + prefix_sum[x][y-1] - prefix_sum[x-1][y-1]

    for _ in range(Q):
        x1, y1, x2, y2 = map(int, readline().split())

        result = (prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1]) // ((x2-x1+1) * (y2-y1+1))
        print(result)

