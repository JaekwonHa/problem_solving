import sys

readline = sys.stdin.readline

from collections import deque


def step1(N, K, numbers):
    dq = deque(['?' for _ in range(N)])

    for a, b in numbers:
        while 0 < a:
            dq.appendleft(dq.pop())
            a -= 1
        if dq[0] != '?' and dq[0] != b:
            return ['!']
        dq[0] = b

    count = {}
    for alphabet in dq:
        if alphabet == '?':
            continue
        if count.get(alphabet) is not None:
            return ['!']
        count[alphabet] = 1

    return dq


if __name__ == '__main__':
    N, K = map(int, readline().split())

    numbers = []
    for i in range(K):
        line = readline()
        numbers.append((int(line.split()[0]), line.split()[1]))

    print(''.join(step1(N, K, numbers)))
