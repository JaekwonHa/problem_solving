import sys
input=sys.stdin.readline


def step1(N, input):
    input.sort(reverse = True)

    answer = 0
    day = input[0][0]
    while day > 0:
        local_max = 0
        local_max_index = 0
        for i in range(len(input)):
            if input[i][0] < day:
                break
            if local_max < input[i][1]:
                local_max = input[i][1]
                local_max_index = i
        if local_max != 0:
            del(input[local_max_index])
            answer += local_max
        day -= 1
    return answer


if __name__ == '__main__':
    N = int(input())

    input = [tuple(map(int, input().split())) for _ in range(N)]

    print(step1(N, input))
