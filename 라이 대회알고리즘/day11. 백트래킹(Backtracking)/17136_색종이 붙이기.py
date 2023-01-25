import sys

sys.setrecursionlimit(10 ** 6)

readline = sys.stdin.readline

MAX = 26


def step1(board, blank_count, paper_count):
    if blank_count == 0:
        return 25 - sum(paper_count)

    answer = MAX
    for x in range(10):
        for y in range(10):
            if board[x][y] == 1:
                for w in range(5, 0, -1):
                    if paper_count[w] <= 0:
                        continue
                    valid = True
                    for xx in range(x, x + w):
                        for yy in range(y, y + w):
                            if not (xx < 10 and yy < 10 and board[xx][yy] == 1):
                                valid = False
                                break
                        if not valid:
                            break
                    if valid:
                        for xx in range(x, x + w):
                            for yy in range(y, y + w):
                                board[xx][yy] = 0
                        paper_count[w] -= 1
                        blank_count -= w * w
                        answer = min(answer, step1(board, blank_count, paper_count))
                        for xx in range(x, x + w):
                            for yy in range(y, y + w):
                                board[xx][yy] = 1
                        paper_count[w] += 1
                        blank_count += w * w
                return answer
    return answer


step2_answer = -1


def step2(board, blank_count, paper_count):
    global step2_answer
    if blank_count == 0:
        if step2_answer == -1:
            step2_answer = 25 - sum(paper_count)
        else:
            step2_answer = min(step2_answer, 25 - sum(paper_count))
        return 25 - sum(paper_count)

    result = 26
    for x in range(10):
        for y in range(10):
            if board[x][y] == 1:
                for w in range(5, 0, -1):
                    if paper_count[w] <= 0:
                        continue
                    if x + w > 10 or y + w > 10:
                        continue
                    valid = True
                    for xx in range(x, x + w):
                        if 0 in board[xx][y:y + w]:
                            valid = False
                            break
                    if valid:
                        for xx in range(x, x + w):
                            for yy in range(y, y + w):
                                board[xx][yy] = 0
                        paper_count[w] -= 1
                        blank_count -= w * w
                        partial_result = step2(board, blank_count, paper_count)
                        for xx in range(x, x + w):
                            for yy in range(y, y + w):
                                board[xx][yy] = 1
                        paper_count[w] += 1
                        blank_count += w * w
                        if step2_answer != -1:
                            if partial_result >= step2_answer:
                                result = min(result, partial_result)
                                return result
                return result
    return result


step3_answer = int(1e9)


def step3(board, blank_count, paper_count):
    global step3_answer
    if blank_count == 0:
        step3_answer = min(step3_answer, 25 - sum(paper_count))
        return

    if step3_answer <= 25 - sum(paper_count):
        return

    for x in range(10):
        for y in range(10):
            if board[x][y] == 1:
                for w in range(5, 0, -1):
                    if paper_count[w] <= 0:
                        continue
                    if x + w > 10 or y + w > 10:
                        continue
                    valid = True
                    for xx in range(x, x + w):
                        if 0 in board[xx][y:y + w]:
                            valid = False
                            break
                    if valid:
                        for xx in range(x, x + w):
                            for yy in range(y, y + w):
                                board[xx][yy] = 0
                        paper_count[w] -= 1
                        step3(board, blank_count - w * w, paper_count)
                        for xx in range(x, x + w):
                            for yy in range(y, y + w):
                                board[xx][yy] = 1
                        paper_count[w] += 1
                return


if __name__ == '__main__':
    board = [list(map(int, readline().split())) for _ in range(10)]
    blank_count = 0
    for i in range(10):
        for j in range(10):
            blank_count += board[i][j]

    if blank_count == 0:
        print(0)
        exit(0)

    paper_count = [
        0,
        5,
        5,
        5,
        5,
        5
    ]

    # answer = step2(board, blank_count, paper_count)
    # if answer == 26:
    #     print(-1)
    # else:
    #     print(answer)

    # step2(board, blank_count, paper_count)
    # print(step2_answer)

    step3(board, blank_count, paper_count)
    if step3_answer == int(1e9):
        print(-1)
    else:
        print(step3_answer)
