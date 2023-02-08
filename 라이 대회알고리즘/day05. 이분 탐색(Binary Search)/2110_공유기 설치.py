import sys
readline=sys.stdin.readline


def step1(N, M, input):
    input.sort()
    lb, rb = 0, input[-1] - input[0]

    if M == 2:
        return rb

    n = {}
    for i in range(N):
        n[input[i]] = i

    while lb <= rb:
        mid = (lb+rb)//2

        count = 0
        prev_point = -1
        for i in range(0, N-1):
            if n.get(input[i]+mid) is not None:
                prev_point = n.get(input[i]+mid)
                count = 2
                break
        if prev_point == -1:
            rb = mid - 1
            break

        for i in range(prev_point+1, N):
            if input[i] - input[prev_point] < mid:
                continue
            if input[i] - input[prev_point] >= mid:
                count += 1
                prev_point = i

        if count >= M:
            lb = mid + 1
        else:
            rb = mid - 1
    return rb


def step2(N, M, input):
    input.sort()
    lb, rb = 0, input[-1] - input[0]

    if M == 2:
        return rb

    while lb <= rb:
        mid = (lb+rb)//2

        count = 1
        prev_point = 0
        answer = 1000000000

        for i in range(1, N):
            if input[i] - input[prev_point] < mid:
                continue
            if input[i] - input[prev_point] >= mid:
                answer = min(answer, input[i] - input[prev_point])
                count += 1
                prev_point = i

        # if answer > mid:
        #     rb = mid - 1
        #     continue

        if count >= M:
            lb = mid + 1
        else:
            rb = mid - 1
    return rb


if __name__ == '__main__':
    N, M = map(int, readline().split())

    input = [int(readline()) for _ in range(N)]

    print(step2(N, M, input))
