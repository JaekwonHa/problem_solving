import sys
readline=sys.stdin.readline




if __name__ == '__main__':
    M = int(readline())
    N = int(readline())

    MAX = 10001
    sieve = [True for _ in range(MAX)]
    sieve[0] = False
    sieve[1] = False
    for i in range(4, MAX, 2):
        sieve[i] = False
    for i in range(3, MAX, 1):
        for j in range(i+i, MAX, i):
            sieve[j] = False

    answer_sum = 0
    answer_min = sys.maxsize
    for i in range(M, N+1):
        if sieve[i]:
            answer_sum += i
            answer_min = min(answer_min, i)

    if answer_sum != 0:
        print(answer_sum)
        print(answer_min)
    else:
        print(-1)
