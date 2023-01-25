import sys
input=sys.stdin.readline


def step1(L, N, TF, TB, input):

    diff = TF - TB

    prev = 0
    input.sort(key = lambda x: x[1], reverse = True)

    answer = 0
    for x, c in input:
        if x < prev:
            continue
        answer += (diff * (x - prev) * c)
        prev = x

    return answer


if __name__ == '__main__':
    L, N, TF, TB = map(int, input().split())

    input = [tuple(map(int, input().split())) for _ in range(N)]

    print(step1(L, N, TF, TB, input))
