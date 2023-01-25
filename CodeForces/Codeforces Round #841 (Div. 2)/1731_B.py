import sys

readline = sys.stdin.readline

if __name__ == '__main__':
    T = int(readline())

    mod = 1000000007
    direction = [
        (0, 1),
        (1, 0)
    ]
    for _ in range(T):
        N = int(readline())
        # answer = 0
        # i, j, d = 1, 1, 0
        # while i != N or j != N:
        #     answer += (i * j)
        #     i += direction[d][0]
        #     j += direction[d][1]
        #     d = (d + 1) % 2
        # answer += N*N
        # answer *= 2022
        # answer %= mod
        # print(answer)

        # answer = 1
        # i = 2
        # while i <= N:
        #     answer += ((i-1)*i) + i*i
        #     i += 1
        # answer *= 2022
        # answer %= mod
        # print(answer)

        one = 1
        two = N*(N+1)*(2*N+1)//6
        three = N*(N+1)//2
        answer = one + 2*(two-1) - (three-1)
        answer *= 2022
        answer %= mod
        print(answer)

