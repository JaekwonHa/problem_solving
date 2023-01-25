



direction = [(1, 0), (0, 1)]


def swap(candy, x_1, y_1, x_2, y_2):
    original = candy[x_1][y_1]
    candy[x_1][y_1] = candy[x_2][y_2]
    candy[x_2][y_2] = original

    return candy


def get_sequential_candy(n, candy, x, y):
    row = 0
    col = 0
    for i in range(x, n):
        if candy[x][y] == candy[i][y]:
            row += 1
        else:
            break
    for j in range(y, n):
        if candy[x][y] == candy[x][j]:
            col += 1
        else:
            break
    return max(row, col)


def step1(n, candy):
    answer = 1

    for x in range(n):
        for y in range(n):
            for d_x, d_y in direction:
                next_x = x + d_x
                next_y = y + d_y
                if next_x < n and next_y < n and candy[x][y] != candy[next_x][next_y]:
                    candy = swap(candy, x, y, next_x, next_y)
                    for xx in range(n):
                        for yy in range(n):
                            answer = max(answer, get_sequential_candy(n, candy, xx, yy))
                    candy = swap(candy, x, y, next_x, next_y)
    return answer


def step2(n, candy):
    answer = 1

    for x in range(n):
        for y in range(n):
            for d_x, d_y in direction:
                next_x = x + d_x
                next_y = y + d_y
                if next_x < n and next_y < n and candy[x][y] != candy[next_x][next_y]:
                    candy[x][y], candy[next_x][next_y] = candy[next_x][next_y], candy[x][y]

                    for xx in range(n):
                        row = 1
                        for yy in range(n-1):
                            if candy[xx][yy] == candy[xx][yy+1]:
                                row += 1
                                answer = max(answer, row)
                            else:
                                row = 1
                    for yy in range(n):
                        col = 1
                        for xx in range(n-1):
                            if candy[xx][yy] == candy[xx+1][yy]:
                                col += 1
                                answer = max(answer, col)
                            else:
                                col = 1

                    candy[x][y], candy[next_x][next_y] = candy[next_x][next_y], candy[x][y]
    return answer




if __name__ == '__main__':

    candy = []

    n = int(input())
    for i in range(n):
        line = input()
        candy.append([*line])
        

    answer = step2(n, candy)

    print(answer)
