import sys

readline = sys.stdin.readline

if __name__ == '__main__':
    N, M = map(int, readline().split())
    numbers = list(map(int, readline().split()))

    prefix_sum = [0 for _ in range(N + 1)]
    for i in range(1, N + 1):
        prefix_sum[i] = prefix_sum[i - 1] + numbers[i - 1]

    prefix_mod = [[] for _ in range(1001)]
    prefix_mod[0].append(0)
    for i in range(1, N + 1):
        prefix_mod[prefix_sum[i] % M].append(i)

    answer = 0
    for i in range(M):
        if prefix_mod[i] and len(prefix_mod[i]) > 1:
            answer += (len(prefix_mod[i]) * (len(prefix_mod[i])-1)) // 2

    print(answer)
