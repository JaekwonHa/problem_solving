import sys

readline = sys.stdin.readline


def step1():
    T = int(readline())

    for _ in range(T):
        N, M = map(int, readline().split())
        board = [list(map(int, readline().split())) for _ in range(N)]

        lb, rb = 1, max(N, M)
        while lb <= rb:
            mid = (lb + rb) // 2

            valid = False
            partial_valid = True
            for i in range(N-mid+1):
                for j in range(M-mid+1):
                    if mid <= board[i][j]:
                        partial_valid = True
                        for ii in range(i, i+mid):
                            for jj in range(j, j+mid):
                                if mid > board[ii][jj]:
                                    partial_valid = False
                                    break
                            if not partial_valid:
                                break
                        if partial_valid:
                            valid = True
                            break
                if valid:
                    break

            if valid:
                lb = mid + 1
            else:
                rb = mid - 1
        print(rb)


def check(N, M, board, height):
    prefix_sum = [[0 for _ in range(M+1)] for _ in range(N+1)]
    auxiliary_board = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            auxiliary_board[i][j] = 1 if board[i][j] >= height else 0
            prefix_sum[i+1][j+1] = auxiliary_board[i][j] + prefix_sum[i+1][j] + prefix_sum[i][j+1] - prefix_sum[i][j]

    for i in range(height, N+1):
        for j in range(height, M+1):
            result = prefix_sum[i][j] - prefix_sum[i-height][j] - prefix_sum[i][j-height] + prefix_sum[i-height][j-height]
            if result == height * height:
                return True
    return False


def step2():
    for _ in range(int(readline())):
        N, M = map(int, readline().split())
        board = [list(map(int, readline().split())) for _ in range(N)]

        lb, rb = 1, max(N, M)
        while lb <= rb:
            mid = (lb + rb) // 2

            valid = check(N, M, board, mid)

            if valid:
                lb = mid + 1
            else:
                rb = mid - 1
        print(rb)


if __name__ == '__main__':
    # step1()
    step2()
