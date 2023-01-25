import sys
from collections import deque
readline=sys.stdin.readline


def encode(numbers):
    bitmask = 0
    for number in numbers:
        bitmask <<= 3
        bitmask += (number - 1)
    return bitmask


def decode(N, bitmask):
    numbers = []
    for _ in range(N):
        temp = bitmask & 7
        numbers.append(temp+1)
        bitmask >>= 3
    numbers.reverse()
    return numbers


if __name__ == '__main__':
    N, K = map(int, readline().split())
    board = list(map(int, readline().split()))

    answer = [i for i in range(1, N+1)]

    level = -1
    q = deque([encode(board)])
    visit = set()

    while len(q) != 0:
        level += 1
        q_size = len(q)
        for _ in range(q_size):
            numbers = decode(N, q.popleft())

            if numbers == answer:
                print(level)
                exit(0)

            for i in range(N-K+1):
                next = encode(numbers[:i] + numbers[i:i+K][::-1] + numbers[i+K:])
                if next not in visit:
                    visit.add(next)
                    q.append(next)

    print(-1)