


def step1(N, L, points):
    prev_point = -1 * L

    answer = 0
    for point in sorted(points):
        if point - prev_point >= L:
            answer += 1
            prev_point = point
    return answer


if __name__ == '__main__':
    N, L = map(int, input().split())

    points = list(map(int, input().split()))

    print(step1(N, L, points))
