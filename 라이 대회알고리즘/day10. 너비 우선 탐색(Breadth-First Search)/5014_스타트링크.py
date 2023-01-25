import sys
from collections import deque

sys.setrecursionlimit(10 ** 6)

readline = sys.stdin.readline
cache = [-1 for _ in range(1000001)]


def step1(F, S, G, U, D):
    visit = [False for _ in range(F + 1)]

    q = deque([S])
    visit[S] = True

    direction = [
        U,
        -D,
    ]

    answer = -1
    while len(q) != 0:
        answer += 1
        q_size = len(q)
        for _ in range(q_size):
            current = q.popleft()
            if current == G:
                return answer
            for d in direction:
                next = current + d
                if 1 <= next <= F:
                    if not visit[next]:
                        visit[next] = True
                        q.append(next)
    else:
        return "use the stairs"


def step2(F, S, G, U, D):
    global cache

    if S == G:
        return 0
    if not (1 <= S <= F):
        return -1

    if cache[S] != -1:
        return cache[S]

    a = step2(F, S + U, G, U, D)
    b = step2(F, S - D, G, U, D)

    if a != -1 and b != -1:
        cache[S] = min(a, b) + 1
    elif a == -1 and b != -1:
        cache[S] = b + 1
    elif a != -1 and b == -1:
        cache[S] = a + 1
    else:
        cache[S] = -1

    return cache[S]


if __name__ == '__main__':
    F, S, G, U, D = map(int, readline().split())

    print(step1(F, S, G, U, D))

    # answer = step2(F, S, G, U, D)
    # print(answer if answer != -1 else "use the stairs")
