import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    N, Q = map(int, readline().split())

    prefix_sum_1 = [0 for _ in range(N+1)]
    prefix_sum_2 = [0 for _ in range(N+1)]
    prefix_sum_3 = [0 for _ in range(N+1)]

    for i in range(1, N+1):
        id = int(readline())
        prefix_sum_1[i] = prefix_sum_1[i-1] + (1 if id == 1 else 0)
        prefix_sum_2[i] = prefix_sum_2[i-1] + (1 if id == 2 else 0)
        prefix_sum_3[i] = prefix_sum_3[i-1] + (1 if id == 3 else 0)

    for _ in range(Q):
        b, a = map(int, readline().split())

        print(f"{prefix_sum_1[a]-prefix_sum_1[b-1]} {prefix_sum_2[a]-prefix_sum_2[b-1]} {prefix_sum_3[a]-prefix_sum_3[b-1]}")
