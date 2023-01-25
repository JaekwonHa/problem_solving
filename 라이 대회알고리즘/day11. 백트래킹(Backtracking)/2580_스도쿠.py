import sys

readline = sys.stdin.readline

find_answer = False


def validate(board):
    for x in range(3):
        for y in range(3):
            temp = set()
            for xx in range(3):
                for yy in range(3):
                    if board[x*3+xx][y*3+yy] != 0 and board[x*3+xx][y*3+yy] in temp:
                        return False
                    temp.add(board[x*3+xx][y*3+yy])

    for y in range(9):
        temp = set()
        for x in range(9):
            if board[x][y] != 0 and board[x][y] in temp:
                return False
            temp.add(board[x][y])

    for x in range(9):
        temp = set()
        for y in range(9):
            if board[x][y] != 0 and board[x][y] in temp:
                return False
            temp.add(board[x][y])

    return True


def validate2(board, x, y, number):
    for i in range(3):
        for j in range(3):
            if board[x//3*3+i][y//3*3+j] == number:
                return False

    for j in range(9):
        if board[x][j] == number:
            return False

    for i in range(9):
        if board[i][y] == number:
            return False

    return True


def print_board(board):
    for i in range(9):
        # print(" ".join(list(map(str, board[i]))))
        print(*board[i])


def step1(board, blank, idx):
    global find_answer
    if len(blank) == idx:
        print_board(board)
        find_answer = True
        return

    x, y = blank[idx]
    for i in range(1, 10):
        # board[x][y] = i
        # if validate(board):
        #     step1(board, blank, idx + 1)
        #     if find_answer:
        #         return
        if validate2(board, x, y, i):
            board[x][y] = i
            step1(board, blank, idx + 1)
            if find_answer:
                return
            board[x][y] = 0


if __name__ == '__main__':

    board = [list(map(int, readline().split())) for _ in range(9)]

    blank = []
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                blank.append((i, j))

    step1(board, blank, 0)
