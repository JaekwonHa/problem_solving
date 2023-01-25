import heapq
import sys
readline=sys.stdin.readline


def step1(numbers):
    from queue import PriorityQueue

    max_heap = PriorityQueue()

    for number in numbers:
        if number == 0:
            if max_heap.qsize() == 0:
                print(0)
            else:
                print(max_heap.get()[1])
        else:
            max_heap.put((-number, number))


def step2(numbers):

    max_heap = []

    for number in numbers:
        if number == 0:
            if len(max_heap) == 0:
                print(0)
            else:
                print(heapq.heappop(max_heap)[1])
        else:
            heapq.heappush(max_heap, (-number, number))


if __name__ == '__main__':
    N = int(readline())

    numbers = [int(readline()) for _ in range(N)]

    # step1(numbers)
    step2(numbers)
