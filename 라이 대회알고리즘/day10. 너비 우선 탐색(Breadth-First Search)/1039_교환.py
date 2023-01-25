import sys
from collections import deque

readline = sys.stdin.readline

if __name__ == '__main__':
    N, K = map(int, readline().split())
    N = str(N)
    digit_count = len(str(N))

    q = deque([N+'|0'])
    visit = {N+'|0'}
    step = -1
    while len(q) != 0:
        step += 1
        q_size = len(q)
        for _ in range(q_size):
            current = q.popleft()
            current, count = current.split('|')
            count = int(count)
            for i in range(digit_count):
                for j in range(i+1, digit_count):
                    exchange = current[:i] + current[j] + current[i+1:j] + current[i] + current[j+1:] + '|' + str(count+1)
                    if not exchange.startswith('0') and exchange not in visit:
                        visit.add(exchange)
                        q.append(exchange)
        if step == K:
            break

    check = False
    for item in visit:
        if item.split('|')[1].endswith(str(K)):
            check = True
    if not check:
        print(-1)
    else:
        answer = 0
        for item in visit:
            current, count = item.split('|')
            count = int(count)
            if count == K:
                answer = max(answer, int(current))
        print(answer)
