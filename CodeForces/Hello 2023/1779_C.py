import sys
from queue import PriorityQueue
readline = sys.stdin.readline


def is_valid():
    global M, prefix_sum
    valid = True
    for i in range(1, M + 1):
        if prefix_sum[i] < prefix_sum[M]:
            valid = False
            break
    return valid


def step1():
    T = int(readline())
    for _ in range(T):
        N, M = map(int, readline().split())
        numbers = list(map(int, readline().split()))

        prefix_sum = [0 for _ in range(N+1)]
        min_value = int(1e9)
        for i in range(1, N+1):
            prefix_sum[i] = numbers[i-1] + prefix_sum[i - 1]
            if i <= M:
                min_value = min(min_value, prefix_sum[i])

        answer = 0
        delta = 0
        visit = set()

        while min_value < prefix_sum[M]:
            max_number = (-1, -1)
            for i in range(M):
                if i not in visit and max_number[0] <= abs(numbers[i]):
                    max_number = (abs(numbers[i]), i)

            numbers[max_number[1]] = -1 * numbers[max_number[1]]
            delta = 2 * numbers[max_number[1]]
            answer += 1
            visit.add(max_number[1])

            for i in range(max_number[1], M+1):
                prefix_sum[i] = numbers[i-1] + prefix_sum[i - 1]
                min_value = min(min_value, prefix_sum[i])

        for i in range(M+1, N+1):
            if prefix_sum[i] + delta < prefix_sum[M]:
                answer += 1
                delta += -2 * numbers[i-1]

        print(answer)


if __name__ == '__main__':
    T = int(readline())
    for _ in range(T):
        N, M = map(int, readline().split())
        numbers = list(map(int, readline().split()))
        M -= 1

        prefix_sum = [0 for _ in range(N)]
        prefix_sum[0] = numbers[0]
        for i in range(1, N):
            prefix_sum[i] = prefix_sum[i-1] + numbers[i]

        answer = 0
        goal = prefix_sum[M]
        max_heap = PriorityQueue()
        for i in range(M, -1, -1):
            if prefix_sum[i] < goal:
                while max_heap.qsize() != 0 and prefix_sum[i] < goal:
                    max_prefix_sum = max_heap.get()[1]
                    goal -= 2*max_prefix_sum
                    answer += 1
            max_heap.put((-numbers[i], numbers[i]))

        goal = prefix_sum[M]
        min_heap = PriorityQueue()
        for i in range(M+1, N):
            min_heap.put(numbers[i])
            if prefix_sum[i] < goal:
                while min_heap.qsize() != 0 and prefix_sum[i] < goal:
                    min_prefix_sum = min_heap.get()
                    goal += 2*min_prefix_sum
                    answer += 1

        print(answer)







