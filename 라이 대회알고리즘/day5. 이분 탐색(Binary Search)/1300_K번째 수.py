import sys
readline=sys.stdin.readline


def step1(N, K):
    lb, rb = 1, N*N

    while lb <= rb:
        mid = (lb + rb)//2

        count = 0
        for i in range(1, N+1):
            count += min(N, mid//i)

        if count <= K-1:
            lb = mid + 1
        else:
            rb = mid - 1
    return lb


if __name__ == '__main__':
    N = int(readline())
    K = int(readline())

    print(step1(N, K))
