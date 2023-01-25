import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    N = int(readline())

    numbers = list(map(int, readline().split()))
    prefix_sum = [0 for _ in range(N+1)]
    for i in range(1, N+1):
        prefix_sum[i] = prefix_sum[i-1] + numbers[i-1]

    M = int(readline())

    for _ in range(M):
        i, j = map(int, readline().split())
        print(prefix_sum[j] - prefix_sum[i-1])



