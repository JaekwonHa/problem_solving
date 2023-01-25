




white_line = ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']
black_line = ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']

white_start_board = [
    white_line,
    black_line,
    white_line,
    black_line,
    white_line,
    black_line,
    white_line,
    black_line
]

black_start_board = [
    black_line,
    white_line,
    black_line,
    white_line,
    black_line,
    white_line,
    black_line,
    white_line
]

candi = [white_start_board, black_start_board]

def step1(M, N, board):
    answer = int(1e9)
    for x in range(M):
        for y in range(N):
            if x + 8 > M or y + 8 > N:
                break
            for c in candi:
                count = 0
                for xx in range(x, x+8):
                    for yy in range(y, y+8):
                        if c[xx-x][yy-y] != board[xx][yy]:
                            count += 1
                answer = min(answer, count)
    return answer


if __name__ == '__main__':
    M, N = map(int, input().split(' '))

    board = []
    for _ in range(M):
        board.append([*input()])
        
    answer = step1(M, N, board)

    print(answer)
