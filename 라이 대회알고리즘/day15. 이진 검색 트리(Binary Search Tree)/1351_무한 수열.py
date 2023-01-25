import sys
sys.setrecursionlimit(10**6)
readline=sys.stdin.readline


def step1_dfs(cache, P, Q, N):
    if N == 0:
        return 1

    if cache.get(N) is not None:
        return cache[N]

    cache[N] = step1_dfs(cache, P, Q, N//P) + step1_dfs(cache, P, Q, N//Q)
    return cache[N]


if __name__ == '__main__':
    N, P, Q = map(int, readline().split())

    cache = {}

    print(step1_dfs(cache, P, Q, N))
