import sys
input=sys.stdin.readline


answer_0 = 0
answer_1 = 0
answer_2 = 0

def step1(x1, y1, x2, y2, input):
    global answer_0
    global answer_1
    global answer_2

    if x1 ==x2 or y1 == y2:
        if input[x1][y1] == -1:
            answer_0 += 1
        if input[x1][y1] == 0:
            answer_1 += 1
        if input[x1][y1] == 1:
            answer_2 += 1
        return 

    prev = input[x1][y1]
    for i in range(x1, x2):
        for j in range(y1, y2):
            if input[i][j] != prev:
                l = (x2 - x1)//3
                step1(x1, y1, x1+l, y1+l, input)
                step1(x1+l, y1, x1+2*l, y1+l, input)
                step1(x1+2*l, y1, x1+3*l, y1+l, input)
                step1(x1, y1+l, x1+l, y1+2*l, input)
                step1(x1+l, y1+l, x1+2*l, y1+2*l, input)
                step1(x1+2*l, y1+l, x1+3*l, y1+2*l, input)
                step1(x1, y1+2*l, x1+l, y1+3*l, input)
                step1(x1+l, y1+2*l, x1+2*l, y1+3*l, input)
                step1(x1+2*l, y1+2*l, x1+3*l, y1+3*l, input)
                return
    
    if input[x1][y1] == -1:
        answer_0 += 1
    if input[x1][y1] == 0:
        answer_1 += 1
    if input[x1][y1] == 1:
        answer_2 += 1
    return


if __name__ == '__main__':
    N = int(input())

    input = [list(map(int, input().split())) for _ in range(N)]

    step1(0, 0, N, N, input)

    print(answer_0)
    print(answer_1)
    print(answer_2)
