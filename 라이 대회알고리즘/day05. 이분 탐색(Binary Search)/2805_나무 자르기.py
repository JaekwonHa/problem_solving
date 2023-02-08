import sys

readline = sys.stdin.readline


def step1(N, M, input):
    left, right, mid = 0, max(input), 0

    while left <= right:
        mid = (left + right) // 2
        answer = 0
        for i in range(0, N):
            answer += max(input[i] - mid, 0)

        # M에 도달했다고 답이 아니라 높이의 최대값을 출력해야함
        # if answer == M:
        #     break
        if answer >= M:
            left = mid+1
        else:
            right = mid-1
    return right


if __name__ == '__main__':
    N, M = map(int, readline().split())

    input = list(map(int, readline().split()))

    print(step1(N, M, input))
