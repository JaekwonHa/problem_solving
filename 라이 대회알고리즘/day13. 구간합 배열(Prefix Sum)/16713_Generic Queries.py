import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    N, Q = map(int, readline().split())
    numbers = list(map(int, readline().split()))

    prefix_sum = [0 for _ in range(N+1)]

    for i in range(1, N+1):
        prefix_sum[i] = numbers[i-1] ^ prefix_sum[i-1]

    answer = 0
    for _ in range(Q):
        s, e = map(int, readline().split())
        answer ^= prefix_sum[e] ^ prefix_sum[s-1]

    print(answer)
