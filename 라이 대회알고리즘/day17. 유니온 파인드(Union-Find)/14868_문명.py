import sys
from collections import deque

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline

direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]


def find(n: int):
    global p
    if p[n] < 0:
        return n
    p[n] = find(p[n])
    return p[n]


def merge(a: int, b: int):
    global p, cost
    a = find(a)
    b = find(b)
    if a == b:
        return
    if a < b:
        p[a] += p[b]
        p[b] = a
    else:
        p[b] += p[a]
        p[a] = b


def step1():
    global p
    N, K = map(int, readline().split())
    p = [-1 for _ in range(K + 1)]

    visit = [[-1 for _ in range(N + 1)] for _ in range(N + 1)]
    level_board = [[-1 for _ in range(N + 1)] for _ in range(N + 1)]
    q = deque([])
    for i in range(1, K + 1):
        x, y = map(int, readline().split())
        q.append((x, y, i))
        visit[x][y] = i
        level_board[x][y] = 0

    remain = K

    level = -1
    while len(q) != 0:
        level += 1
        if remain <= 1:
            break
        q_size = len(q)
        for _ in range(q_size):
            x, y, idx = q.popleft()
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 1 <= nx <= N and 1 <= ny <= N:
                    if visit[nx][ny] == -1:
                        visit[nx][ny] = idx
                        level_board[nx][ny] = level + 1
                        q.append((nx, ny, idx))
                    else:
                        if visit[nx][ny] != idx:
                            if find(idx) != find(visit[nx][ny]):
                                merge(idx, visit[nx][ny])
                                remain -= 1
                                if remain <= 1:
                                    print(max(level_board[x][y], level_board[nx][ny]))
                                    exit(0)


def step2():
    global p
    N, K = map(int, readline().split())
    p = [-1 for _ in range(K + 1)]

    visit = [[-1 for _ in range(N + 1)] for _ in range(N + 1)]

    union_q = deque([])
    bfs_q = deque([])
    for i in range(1, K + 1):
        x, y = map(int, readline().split())
        union_q.append((x, y, i))
        visit[x][y] = i
        # p[i] = i

    remain = K
    level = -1

    while True:
        level += 1

        q_size = len(union_q)
        for _ in range(q_size):
            x, y, idx = union_q.popleft()
            bfs_q.append((x, y, idx))
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 1 <= nx <= N and 1 <= ny <= N:
                    if visit[nx][ny] != -1 and visit[nx][ny] != idx:
                        if find(idx) != find(visit[nx][ny]):
                            merge(idx, visit[nx][ny])
                            remain -= 1
                            if remain <= 1:
                                print(level)
                                exit(0)

        q_size = len(bfs_q)
        for _ in range(q_size):
            x, y, idx = bfs_q.popleft()
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 1 <= nx <= N and 1 <= ny <= N:
                    if visit[nx][ny] == -1:
                        visit[nx][ny] = idx
                        union_q.append((nx, ny, idx))


def step3():
    global p
    N, K = map(int, readline().split())
    p = [-1 for _ in range(K + 1)]

    visit = [[-1 for _ in range(N + 1)] for _ in range(N + 1)]

    bfs_q = deque([])
    for i in range(1, K + 1):
        x, y = map(int, readline().split())
        bfs_q.append((x, y, i))
        visit[x][y] = i

    remain = K
    level = 0

    for i in range(len(bfs_q)):
        x, y, idx = bfs_q[i]
        for dx, dy in direction:
            nx, ny = x + dx, y + dy
            if 1 <= nx <= N and 1 <= ny <= N:
                if visit[nx][ny] != -1 and visit[nx][ny] != idx:
                    # if find(idx) != find(visit[nx][ny]):
                    merge(idx, visit[nx][ny])
                    if p[1] == -K:
                        print(level)
                        exit(0)

    while True:
        level += 1

        q_size = len(bfs_q)
        for _ in range(q_size):
            x, y, idx = bfs_q.popleft()
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 1 <= nx <= N and 1 <= ny <= N:
                    if visit[nx][ny] == -1:
                        visit[nx][ny] = idx
                        bfs_q.append((nx, ny, idx))
                        for dx2, dy2 in direction:
                            nx2, ny2 = nx + dx2, ny + dy2
                            if 1 <= nx2 <= N and 1 <= ny2 <= N:
                                if visit[nx2][ny2] != -1 and visit[nx2][ny2] != idx:
                                    # if find(idx) != find(visit[nx2][ny2]):
                                    merge(idx, visit[nx2][ny2])
                                    if p[1] == K:
                                        print(level)
                                        exit(0)
                    else:
                        # if find(idx) != find(visit[nx][ny]):
                        merge(idx, visit[nx][ny])
                        if p[1] == -K:
                            print(level)
                            exit(0)


def step4():
    global p
    N, K = map(int, readline().split())
    p = [-1 for _ in range(K + 1)]

    visit = {}

    bfs_q = deque([])
    for i in range(1, K + 1):
        x, y = map(int, readline().split())
        bfs_q.append((x, y, i))
        visit[x*N+y] = i

    remain = K
    level = 0

    for i in range(len(bfs_q)):
        x, y, idx = bfs_q[i]
        for dx, dy in direction:
            nx, ny = x + dx, y + dy
            if 1 <= nx <= N and 1 <= ny <= N:
                if visit.get(nx*N+ny) is not None and visit.get(nx*N+ny) != idx:
                    # if find(idx) != find(visit[nx][ny]):
                    merge(idx, visit.get(nx*N+ny))
                    if p[1] == -K:
                        print(level)
                        exit(0)

    while True:
        level += 1

        q_size = len(bfs_q)
        for _ in range(q_size):
            x, y, idx = bfs_q.popleft()
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 1 <= nx <= N and 1 <= ny <= N:
                    if visit.get(nx*N+ny) is None:
                        visit[nx*N+ny] = idx
                        bfs_q.append((nx, ny, idx))
                        for dx2, dy2 in direction:
                            nx2, ny2 = nx + dx2, ny + dy2
                            if 1 <= nx2 <= N and 1 <= ny2 <= N:
                                if visit.get(nx2*N+ny2) is not None and visit.get(nx2*N+ny2) != idx:
                                    # if find(idx) != find(visit[nx2][ny2]):
                                    merge(idx, visit.get(nx2*N+ny2))
                                    if p[1] == -K:
                                        print(level)
                                        exit(0)
                    else:
                        # if find(idx) != find(visit[nx][ny]):
                        merge(idx, visit.get(nx*N+ny))
                        if p[1] == -K:
                            print(level)
                            exit(0)


if __name__ == '__main__':
    # step1()
    # step2()
    # step3()
    step4()
