import sys
readline=sys.stdin.readline



def step1(board):
    stones = []
    diamonds = []
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                stones.append((i, j))
            elif board[i][j] == 2:
                diamonds.append((i, j))

    answer = step1_recursive(stones, diamonds, 0, 0, 0, N-1, N-1)
    return answer if answer != 0 else -1


def is_contains(x, y, sx, sy, ex, ey):
    if sx <= x <= ex and sy <= y <= ey:
        return True
    return False


def step1_recursive(stones, diamonds, prev_direction, sx, sy, ex, ey):
    stone_count = 0
    diamond_count = 0

    for i, j in stones:
        if is_contains(i, j, sx, sy, ex, ey):
            stone_count += 1
    for i, j in diamonds:
        if is_contains(i, j, sx, sy, ex, ey):
            diamond_count += 1

    if stone_count == 0:
        if diamond_count == 1:
            return 1
        return 0
    if stone_count == 1 and diamond_count == 1:
        return 0
    if diamond_count == 0:
        return 0


    answer = 0
    for i, j in stones:
        if is_contains(i, j, sx, sy, ex, ey):
            
            #1 자르지 않는다 ??
            ## 무조건 잘라도 됨. 어차피 잘라서 경우의 수가 없으면 0 return 되고 다른 경우에서 잘리게 됨

            #2 가로 방향으로 자른다
            # 가장 자리에 있으면 자를 수 없다
            if prev_direction == 0 or prev_direction == 2:
                if i in [sx, ex]:
                    break
                # 다이아몬드와 같은 라인에 있으면 자를 수 없다. x, y 범위를 모두 보아야 한다
                for ii, jj in diamonds:
                    if is_contains(ii, jj, sx, sy, ex, ey) and i == ii:
                        break
                else:
                    answer += step1_recursive(stones, diamonds, 1, sx, sy, i-1, ey) * step1_recursive(stones, diamonds, 1, i+1, sy, ex, ey)

            #3 세로 방향으로 자른다
            if prev_direction == 0 or prev_direction == 1:
                # 가장 자리에 있으면 자를 수 없다
                if j in [sy, ey]:
                    break
                # 다이아몬드와 같은 라인에 있으면 자를 수 없다. x, y 범위를 모두 보아야 한다
                for ii, jj in diamonds:
                    if is_contains(ii, jj, sx, sy, ex, ey) and j == jj:
                        break
                else:
                    answer += step1_recursive(stones, diamonds, 2, sx, sy, ex, j-1) * step1_recursive(stones, diamonds, 2, sx, j+1, ex, ey)
    return answer


def step2(board, sx, sy, ex, ey, prev_direction):
    stone_count = 0
    diamond_count = 0
    for i in range(sx, ex):
        for j in range(sy, ey):
            if board[i][j] == 1:
                stone_count += 1
            elif board[i][j] == 2:
                diamond_count += 1

    if stone_count == 0:
        if diamond_count == 1:
            return 1
        return 0
    if stone_count == 1 and diamond_count == 1:
        return 0
    if diamond_count == 0:
        return 0

    answer = 0
    for i in range(sx, ex):
        for j in range(sy, ey):
            if board[i][j] == 1:
                # 가로로 자른다
                if prev_direction == 0 or prev_direction == 2:
                    # 가장 자리는 자를 수 없다.
                    if i in [sx, ex-1]:
                        break
                    # 다이아몬드와 같은 라인에 있으면 자를 수 없다.
                    for jj in range(sy, ey):
                        if board[i][jj] == 2:
                            break
                    else:
                        answer += step2(board, sx, sy, i, ey, 1) * step2(board, i+1, sy, ex, ey, 1)
                # 세로로 자른다
                if prev_direction == 0 or prev_direction == 1:
                    # 가장 자리는 자를 수 없다.
                    if j in [sy, ey-1]:
                        break
                    # 다이아몬드와 같은 라인에 있으면 자를 수 없다.
                    for ii in range(sx, ex):
                        if board[ii][j] == 2:
                            break
                    else:
                        answer += step2(board, sx, sy, ex, j, 2) * step2(board, sx, j+1, ex, ey, 2)
    return answer


if __name__ == '__main__':
    N = int(readline())

    board = [list(map(int, readline().split())) for _ in range(N)]
    
    # print(step1(board))
    answer = step2(board, 0, 0, N, N, 0)
    print(answer) if answer != 0 else print(-1)
