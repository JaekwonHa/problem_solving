import heapq
import sys
readline=sys.stdin.readline


def step1(numbers):
    abs_heap = []

    for number in numbers:
        if number == 0:
            if len(abs_heap) == 0:
                print(0)
            else:
                print(heapq.heappop(abs_heap)[1])
        else:
            heapq.heappush(abs_heap, (abs(number), number))


if __name__ == '__main__':
    N = int(readline())

    numbers = [int(readline()) for _ in range(N)]

    step1(numbers)
