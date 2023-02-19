import sys
from math import sqrt

readline=sys.stdin.readline



# linear sieve 오일러의 체

if __name__ == '__main__':
    N = int(readline())
    numbers = list((map(int, readline().split())))

    MAX = 5000001
    spf = [0 for _ in range(MAX)]
    spf[0] = 0
    spf[1] = 0
    p = []
    for i in range(2, MAX):
        if spf[i] == 0:
            p.append(i)
            spf[i] = i
        for prime in p:
            if i * prime >= MAX: break
            spf[i*prime] = prime
            if i % prime == 0: break

    answer = []
    for number in numbers:
        prime_factor = []
        while spf[number] != 0:
            prime_factor.append(str(spf[number]))
            number //= spf[number]
        answer.append(' '.join(prime_factor))

    for i in range(N):
        print(answer[i])
