import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    T = int(readline())

    for _ in range(T):
        N = int(readline())
        numbers = list(map(int, readline().split()))
        prefix_sum = [0 for _ in range(N+1)]
        for i in range(1, N+1):
            prefix_sum[i] = prefix_sum[i-1] + numbers[i-1]

        answer = sum(numbers)
        for i in range(N):
            for j in range(i, N):
                answer = max(answer, prefix_sum[j+1] - prefix_sum[i])

        print(answer)
