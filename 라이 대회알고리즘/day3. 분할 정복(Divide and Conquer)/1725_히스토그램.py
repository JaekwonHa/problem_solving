import sys
input=sys.stdin.readline


def step1(s, e, numbers):
    if s == e:
        return numbers[s]

    mid = (s+e)//2
    answer = max(step1(s, mid, numbers), step1(mid+1, e, numbers))

    local_sum, local_min, l, r = 1, numbers[mid], mid, mid
    while s < l or r < e:
        q = numbers[r+1] if r < e else -1
        p = numbers[l-1] if s < l else -1
        if p < q:
            local_min = min(local_min, q)
            local_sum += 1
            r += 1
        else:
            local_min = min(local_min, p)
            local_sum += 1
            l -= 1
        answer = max(answer, local_sum * local_min)
    return answer


def step2(N, numbers):
    answer = 0
    stack = []
    heights = [0, *numbers, 0]
    for i in range(0, len(heights)):
        while len(stack) != 0 and heights[stack[-1]] > heights[i]:
            idx = stack[-1]
            stack.pop()
            answer = max(answer, heights[idx] * (i - stack[-1] -1))
        stack.append(i)
    return answer


if __name__ == '__main__':
    N = int(input())

    numbers = [int(input()) for _ in range(N)]

    # print(step1(0, N-1, numbers))
    print(step2(N, numbers))
