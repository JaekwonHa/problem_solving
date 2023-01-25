import sys

readline = sys.stdin.readline

from collections import deque


def step1(N, numbers):
    balloons = []

    for i in range(1, N):
        balloons.append((i+1, numbers[i]))

    answer = []
    idx, step = 1, numbers[0]
    answer.append(idx)

    i = 0
    while len(balloons) > 0:
        if step > 0:
            step -= 1
        i = (i + step) % len(balloons)
        # if i < 0:
        #     i += len(balloons)
        # elif len(balloons) <= i:
        #     i %= len(balloons)
        idx, step = balloons.pop(i)
        answer.append(idx)
    return answer


if __name__ == '__main__':
    N = int(readline())

    numbers = list(map(int, readline().split()))

    print(' '.join(list(map(str, step1(N, numbers)))))
