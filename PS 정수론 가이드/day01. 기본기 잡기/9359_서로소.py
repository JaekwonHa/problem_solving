import sys

readline = sys.stdin.readline

if __name__ == '__main__':

    # 소수 구하기
    MAX = 100001
    sieve = [False for _ in range(MAX)]
    prime = []
    for i in range(4, MAX, 2):
        sieve[i] = True
    for i in range(3, MAX):
        for j in range(i + i, MAX, i):
            sieve[j] = True
    for i in range(2, MAX):
        if not sieve[i]:
            prime.append(i)

    for case in range(int(readline())):
        A, B, N = map(int, input().split(' '))

        # 소인수분해
        prime_factor = {}
        prime_index = 0
        for p in prime:
            if N % p == 0:
                prime_factor[prime_index] = p
                prime_index += 1
            while N % p == 0:
                N //= p
        if N != 1:
            prime_factor[prime_index] = N
            prime_index += 1

        answer = 0

        # 포함배제의 원리
        for bit in range(1, (1 << prime_index)):

            divisor = 1
            cnt = 0
            # 집합 생성
            for i in range(prime_index):
                if bit & (1 << i) > 0:
                    divisor *= prime_factor[i]
                    cnt += 1
            start = A + divisor - 1
            end = B

            start_count = start // divisor
            end_count = end // divisor
            if start_count > end_count: continue

            if cnt & 1 > 0:
                answer += (end_count - start_count + 1)
            else:
                answer -= (end_count - start_count + 1)

        print(f"Case #{case + 1}: {(B - A + 1) - answer}")
