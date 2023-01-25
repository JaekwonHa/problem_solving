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


def step1(R, C, board, visit, used, x, y):
    answer = 0
    for dx, dy in direction:
        nx, ny = x + dx, y + dy
        if 0 <= nx < R and 0 <= ny < C:
            if not visit[nx][ny] and not used[ord(board[nx][ny])]:
                visit[nx][ny] = True
                used[ord(board[nx][ny])] = True
                answer = max(answer, step1(R, C, board, visit, used, nx, ny))
                visit[nx][ny] = False
                used[ord(board[nx][ny])] = False
    return answer + 1


def step2(R, C, board):
    q = deque([(0, 0, board[0][0])])
    step = 0
    while len(q) != 0:
        q_size = len(q)
        step += 1
        for _ in range(q_size):
            x, y, path = q.popleft()
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 0 <= nx < R and 0 <= ny < C:
                    if board[nx][ny] not in path:
                        q.append((nx, ny, path + board[nx][ny]))
    return step


def step3(R, C, board):
    q = set([(0, 0, board[0][0])])
    step = 0
    while len(q) != 0:
        q_size = len(q)
        for _ in range(q_size):
            x, y, path = q.pop()
            step = max(step, len(path))
            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 0 <= nx < R and 0 <= ny < C:
                    if board[nx][ny] not in path:
                        q.add((nx, ny, path + board[nx][ny]))
    return step


if __name__ == '__main__':
    R, C = map(int, readline().split())

    board = [readline().replace('\n', '') for _ in range(R)]
    visit = [[False for _ in range(C)] for _ in range(R)]
    used = [False for _ in range(ord('Z') + 1)]

    # visit[0][0] = True
    # used[ord(board[0][0])] = True
    # print(step1(R, C, board, visit, used, 0, 0))

    # print(step2(R, C, board))
    print(step3(R, C, board))
