import sys

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline


def TSP(N, board, visit, cache, idx):
    if cache[idx][visit] != -1:
        return cache[idx][visit]

    answer = int(1e9)
    if visit == (1 << N) - 1:
        if board[idx][0] != 0:
            answer = board[idx][0]
    else:
        for i, score in enumerate(board[idx]):
            if score != 0:
                if visit & (1 << i) == 0:
                    visit |= (1 << i)
                    answer = min(answer, TSP(N, board, visit, cache, i) + score)
                    visit &= ~(1 << i)
    cache[idx][visit] = answer
    return answer


if __name__ == '__main__':
    N = int(readline())

    board = [list(map(int, readline().split())) for _ in range(N)]
    visit = (1 << 0)

    cache = [[-1 for _ in range(1 << N)] for _ in range(N)]
    print(TSP(N, board, visit, cache, 0))
