import sys
readline=sys.stdin.readline

from collections import deque


if __name__ == '__main__':
    T = int(readline())

    for _ in range(T):
        N, M = map(int, readline().split())

        document = list(map(int, readline().split()))

        if N == 1:
            print(1)
            continue

        q = deque([i for i in range(N)])
        answer = 0

        while len(q) != 0:

            max_priority = 0
            for i in range(1, len(q)):
                max_priority = max(max_priority, document[q[i]])

            if document[q[0]] < max_priority:
                q.append(q.popleft())
                continue

            answer += 1
            i = q.popleft()
            if i == M:
                print(answer)
                break
