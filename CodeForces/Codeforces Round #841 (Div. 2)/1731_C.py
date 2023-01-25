import math
import sys

readline = sys.stdin.readline


def step1():
    T = int(readline())

    for _ in range(T):
        N = int(readline())
        numbers = list(map(int, readline().split()))

        prefix_xor = [0 for _ in range(N)]
        prefix_xor[0] = numbers[0]
        for i in range(1, N):
            prefix_xor[i] = prefix_xor[i - 1] ^ numbers[i]

        answer = 0
        for i in range(N):
            for j in range(i, N):
                temp = prefix_xor[j] ^ prefix_xor[i - 1] if i != 0 else prefix_xor[j]
                if temp != math.sqrt(temp) * math.sqrt(temp):
                    # if temp & 1 == 1:
                    # print(numbers[i:j+1])
                    answer += 1
        print(answer)


def step2():
    perfect_square_list = []
    limit = int(math.sqrt(400000))
    for i in range(limit):
        perfect_square_list.append(i * i)

    for _ in range(int(readline())):
        N = int(readline())
        numbers = list(map(int, readline().split()))
        limit = 2*N

        cache = [0] * limit

        count = 0
        prefix_xor = 0
        cache[prefix_xor] += 1
        for j in range(N):
            prefix_xor ^= numbers[j]

            for perfect_square in perfect_square_list:
                if perfect_square >= limit:
                    break
                if prefix_xor ^ perfect_square < limit:
                    count += cache[prefix_xor ^ perfect_square]

            cache[prefix_xor] += 1

        answer = (N * (N + 1) // 2) - count
        print(answer)


if __name__ == '__main__':
    # step1()
    step2()

