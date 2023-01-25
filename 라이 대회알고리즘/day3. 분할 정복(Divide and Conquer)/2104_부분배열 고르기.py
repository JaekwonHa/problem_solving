import sys
input=sys.stdin.readline


n = []

def step1(i, j):
    if i == j:
        return n[i] * n[i]

    global n
    answer = sum(n[i:j]) * min(n[i:j])
    return max(answer, step1(i+1, j), step1(i, j-1))


if __name__ == '__main__':
    N = int(input())

    n = list(map(int, input().split()))

    print(step1(0, N))
