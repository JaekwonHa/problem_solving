import copy
import heapq
import sys
from collections import deque
readline=sys.stdin.readline


if __name__ == '__main__':
    T = int(readline())
    for _ in range(T):
        M = int(readline())
        numbers = []
        for i in range(0, M, 10):
            numbers.extend(list(map(int, readline().split())))

        high = []
        low = []

        mid = numbers[0]
        answer = [mid]

        for i in range(1, M):
            if i % 2 == 1:
                # 짝수
                if mid < numbers[i]:
                    heapq.heappush(high, (numbers[i], numbers[i]))
                    heapq.heappush(low, (-mid, mid))
                else:
                    heapq.heappush(high, (mid, mid))
                    heapq.heappush(low, (-numbers[i], numbers[i]))
            else:
                # 홀수
                if high[0][1] < numbers[i]:
                    mid = heapq.heappop(high)[1]
                    heapq.heappush(high, (numbers[i], numbers[i]))
                elif numbers[i] < low[0][1]:
                    mid = heapq.heappop(low)[1]
                    heapq.heappush(low, (-numbers[i], numbers[i]))
                else:
                    mid = numbers[i]
                answer.append(mid)

        print(len(answer))
        for i in range(0, len(answer), 10):
            print(*answer[i:min(i+10, len(answer))])
