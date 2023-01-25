import sys

readline = sys.stdin.readline

if __name__ == '__main__':
    T = int(readline())
    for _ in range(T):
        N = int(readline())

        if N % 2 == 0:
            answer = []
            for _ in range(N//2):
                answer.append(1)
                answer.append(-1)

            print("YES")
            print(*answer)
            continue

        if N == 3:
            print("NO")
            continue

        k = N//2
        answer = [k-1]
        for _ in range(N//2):
            answer.append(-k)
            answer.append(k-1)
        print("YES")
        print(*answer)

