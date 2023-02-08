import sys
readline=sys.stdin.readline


def step1(N, K, D, input):
    lb, rb = 1, N

    while lb <= rb:
        mid = (lb + rb)//2

        count = 0
        for i in range(K):
            if input[i][0] <= mid:
                count += 1 + (min(input[i][1], mid) - input[i][0])//input[i][2]

        if count < D:
            lb = mid + 1
        else:
            rb = mid - 1
    return lb


if __name__ == '__main__':
    N, K, D = map(int, readline().split())

    input = [list(map(int, readline().split())) for _ in range(K)]

    print(step1(N, K, D, input))
