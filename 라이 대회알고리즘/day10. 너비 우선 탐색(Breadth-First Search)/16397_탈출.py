import sys
from collections import deque
readline=sys.stdin.readline


if __name__ == '__main__':
    N, T, G = map(int, readline().split())

    visit = [False for _ in range(100000)]
    q = deque([N])
    visit[N] = True

    answer = -1
    while len(q) != 0:
        q_size = len(q)
        answer += 1
        if answer > T:
            break
        for _ in range(q_size):
            current = q.popleft()

            if current == G:
                print(answer)
                exit(0)

            # button 1
            button1 = current + 1
            if 0 <= button1 < 100000 and not visit[button1]:
                q.append(button1)
                visit[button1] = True

            # button 2
            if current != 0 and current*2 < 100000:
                button2 = current * 2
                # next -= 10**(len(str(next))-1)
                button2 = int(str(int(str(button2)[0]) - 1) + str(button2)[1:])
                if 0 <= button2 < 100000 and not visit[button2]:
                    q.append(button2)
                    visit[button2] = True
    print("ANG")