import sys
from collections import deque

readline=sys.stdin.readline


if __name__ == '__main__':
    N = int(readline())
    q = deque([i for i in range(2, N+1, 2)])

    while len(q) != 1:
        q.popleft()
        q.append(q.popleft())

    print(q[0])

