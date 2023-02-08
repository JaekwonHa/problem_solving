import sys
readline=sys.stdin.readline


def step1(N, M, input):
    lb, rb = 1, max(input)

    while lb <= rb:
        mid = (lb+rb)//2

        count = 0
        for i in range(N):
            count += (input[i]//mid)

        if count >= M:
            lb = mid + 1
        else:
            rb = mid - 1
    return rb



if __name__ == '__main__':
    N, M = map(int, readline().split())

    input = [int(readline()) for _ in range(N)]

    print(step1(N, M, input))
