import sys
readline=sys.stdin.readline


def step1(N, M, input):
    lb, rb, limit = 0, sum(input), max(input)

    while lb <= rb:
        mid, remain, count = (lb + rb)//2, 0, 0

        if limit <= mid:
            for i in range(N):
                if 0 <= remain - input[i]:
                    remain -= input[i]
                else:
                    remain = mid - input[i]
                    count += 1

            if count <= M:
                rb = mid - 1
            else:
                lb = mid + 1
        else:
            lb = mid + 1
    return lb


if __name__ == '__main__':
    N, M = map(int, readline().split())

    input = [int(readline()) for _ in range(N)]

    print(step1(N, M, input))
