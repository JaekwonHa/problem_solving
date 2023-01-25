import sys

readline = sys.stdin.readline


def step1(N, M, input):
    lb, rb, limit = 0, sum(input), max(input)

    while lb <= rb:
        mid = (lb + rb) // 2

        if limit <= mid:
            count = 1
            size = input[0]
            for i in range(1, N):
                if size + input[i] <= mid:
                    size += input[i]
                else:
                    count += 1
                    size = input[i]
            if count <= M:
                rb = mid - 1
            else:
                lb = mid + 1
        else:
            lb = mid + 1
    return lb


if __name__ == '__main__':
    N, M = map(int, readline().split())

    input = list(map(int, readline().split()))

    print(step1(N, M, input))
