import sys

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline


direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]
max_depth = 0
deep_node = 0


def step1():
    T = int(readline())
    for _ in range(T):
        max_depth = 0
        deep_node = 0

        C, R = map(int, readline().split())
        board = [readline().replace('\n', '') for _ in range(R)]

        start = 1
        edges = [[] for _ in range(R*C+1)]
        for x in range(R):
            for y in range(C):
                if board[x][y] == '.':
                    node = C * x + y
                    start = node
                    for dx, dy in direction:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < R and 0 <= ny < C:
                            if board[nx][ny] == '.':
                                next_node = C * nx + ny
                                edges[node].append(next_node)

        for i in range(len(edges)):
            if len(edges[i]) == 1:
                start = i
                break

        visit = [False for _ in range(R*C+1)]
        step1_dfs(edges, visit, start, 0)

        visit = [False for _ in range(R*C+1)]
        step1_dfs(edges, visit, deep_node, 0)

        print(f"Maximum rope length is {max_depth}.")


def step1_dfs(edges, visit, current, depth):
    global max_depth, deep_node
    visit[current] = True

    if max_depth < depth:
        max_depth = depth
        deep_node = current

    for next in edges[current]:
        if not visit[next]:
            step1_dfs(edges, visit, next, depth+1)


from collections import deque


def step2():
    global max_depth, deep_node
    T = int(readline())
    for _ in range(T):
        max_depth = 0
        deep_node = (-1, -1, 0)

        C, R = map(int, readline().split())
        board = [readline().replace('\n', '') for _ in range(R)]

        start = find_start(R, C, board)
        q = deque([start])
        visit = [[False for _ in range(C)] for _ in range(R)]
        visit[start[0]][start[1]] = True
        while len(q) != 0:
            x, y, depth = q.popleft()
            if max_depth < depth:
                max_depth = depth
                deep_node = (x, y, 0)
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 0 <= nx < R and 0 <= ny < C and board[nx][ny] == '.' and not visit[nx][ny]:
                    visit[nx][ny] = True
                    q.append((nx, ny, depth+1))

        q = deque([deep_node])
        visit = [[False for _ in range(C)] for _ in range(R)]
        visit[deep_node[0]][deep_node[1]] = True
        while len(q) != 0:
            x, y, depth = q.popleft()
            if max_depth < depth:
                max_depth = depth
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 0 <= nx < R and 0 <= ny < C and board[nx][ny] == '.' and not visit[nx][ny]:
                    visit[nx][ny] = True
                    q.append((nx, ny, depth+1))

        print(f"Maximum rope length is {max_depth}.")


def find_start(R, C, board):
    for x in range(R):
        for y in range(C):
            if board[x][y] == '.':
                return x, y, 0
    #             path = 0
    #             for dx, dy in direction:
    #                 nx, ny = x + dx, y + dy
    #                 if 0 <= nx < R and 0 <= ny < C:
    #                     if board[nx][ny] == '.':
    #                         path += 1
    #             if path <= 1:
    #                 return x, y, 0
    # return 0, 0, 0


if __name__ == '__main__':
    step2()
