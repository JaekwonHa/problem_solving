import copy
import heapq
import sys
from collections import deque
readline=sys.stdin.readline


def step1():
    K, N = map(int, readline().split())
    primes = list(map(int, readline().split()))
    primes.sort()

    numbers = deque(primes)
    answer = copy.deepcopy(primes)
    visit = set()

    finish = False
    while True:
        q_size = len(numbers)
        for _ in range(q_size):
            number = numbers.popleft()
            min_value = int(1 << 31)
            for prime in primes:
                min_value = min(min_value, number * prime)
                if number * prime not in visit:
                    visit.add(number * prime)
                    answer.append(number * prime)
                    numbers.append(number * prime)
            if int(1 << 31) <= min_value:
                finish = True
                break
        if finish:
            break

    answer.sort()
    print(answer[N-1])


def step2():
    K, N = map(int, readline().split())
    primes = list(map(int, readline().split()))

    pq = copy.deepcopy(primes)
    heapq.heapify(pq)
    op = 0
    while True:
        number = heapq.heappop(pq)
        if len(pq) != 0 and number == pq[0]:
            continue
        op += 1
        if op == N:
            print(number)
            exit(0)
        for prime in primes:
            if (1<<31) <= number * prime:
                continue
            heapq.heappush(pq, number * prime)


if __name__ == '__main__':
    step2()
