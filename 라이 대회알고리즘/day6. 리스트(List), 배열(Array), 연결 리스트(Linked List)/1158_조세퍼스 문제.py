import sys

readline = sys.stdin.readline

from collections import deque


def step1(N, K):
    dq = deque([i for i in range(1, N + 1)])  # deque([1, 2, 3,...,n])

    answer = []
    while len(answer) < N:
        i = K
        while 0 < i:
            dq.append(dq.popleft())
            i -= 1
        answer.append(dq.pop())
    return answer


if __name__ == '__main__':
    N, K = map(int, readline().split())

    answer = step1(N, K)
    answer = list(map(str, answer))
    print(f'<{", ".join(answer)}>')
