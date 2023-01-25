import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    N = int(readline())

    board = [[0 for _ in range(N)] for _ in range(N)]

    points = []
    for _ in range(N):
        a, b = map(int, readline().split())
        points.append((a, b))

    coordi_compaction_x = {}
    coordi_compaction_y = {}

    points = sorted(points, key=lambda x: (x[0], x[1]))
    for i in range(N):
        coordi_compaction_x[points[i][0]] = i

    points = sorted(points, key=lambda x: (x[1], x[0]))
    for i in range(N):
        coordi_compaction_y[points[i][1]] = i

    for x, y in points:
        compaction_x, compaction_y = coordi_compaction_x[x], coordi_compaction_y[y]
        board[compaction_x][compaction_y] += 1

    prefix_sum = [[0 for _ in range(N+1)] for _ in range(N+1)]
    for x in range(1, N+1):
        for y in range(1, N+1):
            prefix_sum[x][y] = board[x-1][y-1] + prefix_sum[x][y-1] + prefix_sum[x-1][y] - prefix_sum[x-1][y-1]

    answer = int(1e9)
    for x in range(1, N):
        for y in range(1, N):
            local_answer = 0

            x1, y1, x2, y2 = 1, 1, x, y
            result = prefix_sum[x2][y2] - prefix_sum[x2][y1-1] - prefix_sum[x1-1][y2] + prefix_sum[x1-1][y1-1]
            local_answer = max(local_answer, result)

            x1, y1, x2, y2 = 1, y+1, x, N
            result = prefix_sum[x2][y2] - prefix_sum[x2][y1-1] - prefix_sum[x1-1][y2] + prefix_sum[x1-1][y1-1]
            local_answer = max(local_answer, result)

            x1, y1, x2, y2 = x+1, 1, N, y
            result = prefix_sum[x2][y2] - prefix_sum[x2][y1-1] - prefix_sum[x1-1][y2] + prefix_sum[x1-1][y1-1]
            local_answer = max(local_answer, result)

            x1, y1, x2, y2 = x+1, y+1, N, N
            result = prefix_sum[x2][y2] - prefix_sum[x2][y1-1] - prefix_sum[x1-1][y2] + prefix_sum[x1-1][y1-1]
            local_answer = max(local_answer, result)

            answer = min(answer, local_answer)

    print(answer)
