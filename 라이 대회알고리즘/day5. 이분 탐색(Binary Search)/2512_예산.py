import sys

readline = sys.stdin.readline


def step1(n, k, input):
    lb, rb = 0, max(input)

    while lb <= rb:
        mid = (lb + rb) // 2
        budget = 0
        for i in input:
            budget += (i - max(0, i - mid))
        if budget > k:
            rb = mid - 1
        else:
            lb = mid + 1
    return rb


if __name__ == '__main__':
    N = int(readline())
    input = list(map(int, readline().split()))
    K = int(readline())

    print(step1(N, K, input))
