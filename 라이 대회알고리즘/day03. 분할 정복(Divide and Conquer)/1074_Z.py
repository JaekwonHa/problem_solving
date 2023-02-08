import sys
readline=sys.stdin.readline


sys.setrecursionlimit(10**6)


def step1(N, r, c):
    if N == 1:
        if (r, c) == (0, 0):
            return 0
        if (r, c) == (0, 1):
            return 1
        if (r, c) == (1, 0):
            return 2
        if (r, c) == (1, 1):
            return 3

    half = 2**(N-1)
    if r < half and c < half:
        return step1(N-1, r, c)
    if r < half and half < c:
        return step1(N-1, r, c-half) + (half*half)
    if half < r and c < half:
        return step1(N-1, r-half, c) + (half*half)*2
    
    return step1(N-1, r-half, c-half) + (half*half)*3


def step2(N, r, c):
    answer = 0

    half = 2**N
    while 1 < N:
        half //= 2
        if r < half and c < half:
            N -= 1
        elif r < half and half <= c:
            N -= 1
            c -= half
            answer += (half*half)
        elif half <= r and c < half:
            N -= 1
            r -= half
            answer += (half*half)*2
        else:
            N -= 1
            r -= half
            c -= half
            answer += (half*half)*3
    
    if (r, c) == (0, 0):
        answer += 0
    if (r, c) == (0, 1):
        answer += 1
    if (r, c) == (1, 0):
        answer += 2
    if (r, c) == (1, 1):
        answer += 3
    
    return answer


if __name__ == '__main__':
    N, r, c = tuple(map(int, readline().split()))

    print(step1(N, r, c))
    # print(step2(N, r, c))
