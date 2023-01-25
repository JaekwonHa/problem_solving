import heapq
import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    N = int(readline())

    pq = []
    for number in map(int, readline().split()):
        heapq.heappush(pq, number)

    for _ in range(1, N):
        for number in map(int, readline().split()):
            if number <= pq[0]:
                continue
            heapq.heappop(pq)
            heapq.heappush(pq, number)

    print(pq[0])
