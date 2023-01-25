import sys
from collections import deque

readline = sys.stdin.readline

direction = [
    (0, 1),
    (0, -1),
    (1, 0),
    (-1, 0)
]


def encode(board):
    return "".join(list([*board[0], *board[1], *board[2]]))


def decode(hash):
    return [[row[0], row[1], row[2]] for row in [hash[:3], hash[3:6], hash[6:]]]


if __name__ == '__main__':
    board = [tuple(readline().split()) for _ in range(3)]
    answer = "123456780"

    step = -1
    visit = set()
    first_board = encode(board)
    q = deque([first_board])
    visit.add(first_board)
    while len(q) != 0:
        step += 1
        q_size = len(q)
        for _ in range(q_size):
            current = q.popleft()
            if current == answer:
                print(step)
                exit(0)

            x, y = 0, 0
            temp_board = decode(current)
            for i, row in enumerate(temp_board):
                if '0' in row:
                    x, y = i, row.index('0')
                    break

            for dx, dy in direction:
                nx, ny = x + dx, y + dy
                if 0 <= nx < 3 and 0 <= ny < 3:
                    temp_board[x][y], temp_board[nx][ny] = temp_board[nx][ny], temp_board[x][y]

                    temp_board_hash = encode(temp_board)
                    if temp_board_hash not in visit:
                        visit.add(temp_board_hash)
                        q.append(temp_board_hash)

                    temp_board[x][y], temp_board[nx][ny] = temp_board[nx][ny], temp_board[x][y]
    print(-1)
