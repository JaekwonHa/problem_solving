import sys
readline=sys.stdin.readline


pattern = [
    "***",
    "* *",
    "***"
]

board = [[" " for _ in range(3**8)] for _ in range(3**8)]

def step1(N, sx, sy, ex, ey):
    if N == 3:
        for i in range(3):
            for j in range(3):
                board[sx+i][sy+j] = pattern[i][j]
        return
    
    length = N//3
    step1(length, sx, sy, sx+length, sy+length)
    step1(length, sx, sy+length, sx+length, sy+length*2)
    step1(length, sx, sy+length*2, sx+length, sy+length*3)

    step1(length, sx+length, sy, sx+length*2, sy+length)
    # step1(length, sx+length, sy+length, sx+length*2, sy+length*2)
    step1(length, sx+length, sy+length*2, sx+length*2, sy+length*3)

    step1(length, sx+length*2, sy, sx+length*3, sy+length)
    step1(length, sx+length*2, sy+length, sx+length*3, sy+length*2)
    step1(length, sx+length*2, sy+length*2, sx+length*3, sy+length*3)
    return

if __name__ == '__main__':
    N = int(readline())

    step1(N, 0, 0, N, N)

    for row in board[:N]:
        print("".join(row[:N]))
