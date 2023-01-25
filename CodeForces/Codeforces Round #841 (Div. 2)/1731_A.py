import sys

readline = sys.stdin.readline

if __name__ == '__main__':
    T = int(readline())

    for _ in range(T):
        N = int(readline())
        numbers = list(map(int, readline().split()))
        answer = 1
        for number in numbers:
            answer *= number

        answer += (N-1)
        answer *= 2022
        print(answer)
