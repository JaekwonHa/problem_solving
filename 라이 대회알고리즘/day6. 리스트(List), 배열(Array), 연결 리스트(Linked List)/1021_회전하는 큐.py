import sys

readline = sys.stdin.readline

from collections import deque


def step1(N, M, numbers):
    dq = deque([i for i in range(1, N + 1)])  # deque([1, 2, 3,...,n])

    answer = 0
    for n in numbers:
        while True:
            if dq[0] == n:
                dq.popleft()
                break
            else:
                answer += 1
                if dq.index(n) <= len(dq)//2:
                    dq.append(dq.popleft())
                else:
                    dq.appendleft(dq.pop())
    return answer


if __name__ == '__main__':
    N, M = map(int, readline().split())

    numbers = list(map(int, readline().split()))

    print(step1(N, M, numbers))
