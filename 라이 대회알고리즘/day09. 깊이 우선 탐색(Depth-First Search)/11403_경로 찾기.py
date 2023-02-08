import sys
readline=sys.stdin.readline

INF = int(1e9)

if __name__ == '__main__':
    N = int(readline())

    adj = [list(map(int, readline().split())) for _ in range(N)]

    board = [[INF for _ in range(N)] for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if adj[i][j] == 1:
                board[i][j] = 1

    for k in range(N):
        for i in range(N):
            for j in range(N):
                board[i][j] = min(board[i][j], board[i][k] + board[k][j])

    for i in range(N):
        for j in range(N):
            if board[i][j] == INF:
                print(0, end=" ")
            else:
                print(1, end=" ")
        print("")

