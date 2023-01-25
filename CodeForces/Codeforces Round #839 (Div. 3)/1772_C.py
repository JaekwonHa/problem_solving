import sys

readline = sys.stdin.readline

if __name__ == '__main__':
    N = int(readline())

    for i in range(N):
        k, n = map(int, readline().split())

        answer = ["1"]

        count_k = 1
        step = 1
        for j in range(2, n + 1):
            if len(answer) == k:
                break
            if step + (k - 1 - len(answer)) <= n - int(answer[-1]):
                answer.append(str(int(answer[-1]) + step))
                step += 1
            else:
                answer.append(str(int(answer[-1]) + 1))

        print(" ".join(answer))
