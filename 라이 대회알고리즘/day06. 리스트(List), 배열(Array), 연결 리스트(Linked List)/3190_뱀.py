import sys
from collections import deque

readline = sys.stdin.readline

direction = [
    (0, 1),
    (1, 0),
    (0, -1),
    (-1, 0)
]


def step1(N, K, apple, L, command):
    d = 0
    dq = deque([(1, 1)])

    time = 0
    while True:
        if 0 < len(command) and int(command[0][0]) == time:
            if command[0][1] == 'D':
                d = (d + 1) % 4
            if command[0][1] == 'L':
                d = (d - 1)
                if d < 0:
                    d += 4
            del command[0]

        time += 1
        head = (dq[0][0] + direction[d][0], dq[0][1] + direction[d][1])
        if 0 < head[0] <= N and 0 < head[1] <= N and dq.count(head) == 0:
            dq.appendleft(head)
            if apple.count(head) == 0:
                dq.pop()
            else:
                del apple[apple.index(head)]
        else:
            break
    return time


if __name__ == '__main__':
    N = int(readline())
    K = int(readline())

    apple = [tuple(map(int, readline().split())) for _ in range(K)]

    L = int(readline())
    command = [tuple(readline().replace('\n', '').split()) for _ in range(L)]

    print(step1(N, K, apple, L, command))
