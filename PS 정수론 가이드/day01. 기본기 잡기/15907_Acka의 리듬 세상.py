import sys
from collections import defaultdict

readline=sys.stdin.readline



if __name__ == '__main__':
    N = int(readline())
    numbers = list(map(int, readline().split()))

    # 소수 구하기
    # MAX = 1000001
    # sieve = [False for _ in range(MAX)]
    # prime = []
    # for i in range(4, MAX, 2):
    #     sieve[i] = True
    # for i in range(3, MAX):
    #     for j in range(i + i, MAX, i):
    #         sieve[j] = True
    # for i in range(2, MAX):
    #     if not sieve[i]:
    #         prime.append(i)


    MAX = 1000001
    spf = [0 for _ in range(MAX)]
    prime = []
    for i in range(2, MAX):
        if spf[i] == 0:
            prime.append(i)
        for p in prime:
            if i * p >= MAX: break
            spf[i * p] = 1
            if i % p == 0: break


    answer = 0
    for ai in prime:
        sieve = defaultdict(int)
        for aj in numbers:
            sieve[aj % ai] += 1
            answer = max(answer, sieve[aj % ai])

    print(answer)
