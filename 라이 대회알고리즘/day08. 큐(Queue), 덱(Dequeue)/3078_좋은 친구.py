import sys
readline=sys.stdin.readline

from collections import deque



def step1(N, K):
    student = [readline() for _ in range(N)]

    q = [deque([]) for _ in range(21)]

    for i in range(N):
        q[len(student[i])].append(i)

    answer = 0

    for i in range(2, 21):
        j = 1
        while len(q[i]) != 0:
            rank = q[i].popleft()
            j = max(0, j - 1)
            while j < len(q[i]) and (q[i][j] - rank) <= K:
                j += 1
            answer += j
    return answer


def step2(N, K):
    q = [deque([]) for _ in range(30)]

    answer = 0
    for i in range(N):
        name = len(readline())

        # if len(q[name]) == 0:
        #     q[name].append(i)
        #     continue

        while len(q[name]) != 0 and i - q[name][0] > K:
            q[name].popleft()

        answer += len(q[name])
        q[name].append(i)

    return answer


if __name__ == '__main__':
    N, K = map(int, readline().split())


    # print(step1(N, K))
    print(step2(N, K))
