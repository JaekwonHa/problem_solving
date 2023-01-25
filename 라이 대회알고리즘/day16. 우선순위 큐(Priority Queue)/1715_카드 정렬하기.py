import heapq
import sys
readline=sys.stdin.readline


def step1(numbers):
    min_heap = numbers
    heapq.heapify(min_heap)

    answer = 0
    while len(min_heap) > 1:
        first = heapq.heappop(min_heap)
        second = heapq.heappop(min_heap)
        answer += (first + second)
        heapq.heappush(min_heap, first+second)

    # answer += sum(min_heap)
    print(answer)


if __name__ == '__main__':
    N = int(readline())

    numbers = [int(readline()) for _ in range(N)]

    step1(numbers)
