import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    N, Q = map(int, readline().split())

    numbers = list(map(int, readline().split()))

    delta_numbers = [0 for _ in range(N)]
    for i in range(0, N-1):
        delta_numbers[i] = abs(numbers[i+1] - numbers[i])

    prefix_sum = [0 for _ in range(N)]
    for i in range(1, N):
        prefix_sum[i] = prefix_sum[i-1] + delta_numbers[i-1]

    for _ in range(Q):
        i, j = map(int, readline().split())
        if j-1 < i:
            print(0)
        else:
            print(prefix_sum[j-1] - prefix_sum[i-1])



