import sys

readline = sys.stdin.readline


def step1(N, DP, used, count, last):
    if N == count:
        if used == (1 << 10) - 1:
            return 1
        return 0

    if DP[count][last][used] != -1:
        return DP[count][last][used]

    answer = 0

    next = last - 1
    if next >= 0:
        if used & (1 << next) == 0:
            used |= (1 << next)
            answer += step1(N, DP, used, count + 1, next)
            used &= ~(1 << next)
        else:
            answer += step1(N, DP, used, count + 1, next)

    next = last + 1
    if next <= 9:
        if used & (1 << next) == 0:
            used |= (1 << next)
            answer += step1(N, DP, used, count + 1, next)
            used &= ~(1 << next)
        else:
            answer += step1(N, DP, used, count + 1, next)

    DP[count][last][used] = answer
    return answer


if __name__ == '__main__':
    N = int(readline())

    DP = [[[-1 for _ in range(1 << 9 + 1)] for _ in range(10)] for _ in range(N+1)]

    answer = 0
    for i in range(1, 10):
        answer += step1(N, DP, 1 << i, 1, i)

    print(answer % 1000000000)
