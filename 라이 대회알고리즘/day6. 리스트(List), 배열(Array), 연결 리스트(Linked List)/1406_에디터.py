import sys

readline = sys.stdin.readline

from collections import deque


def step1(content, M, command):
    dq = deque([content[i] for i in range(len(content))])

    cursor = len(content)
    for c in command:
        if c[0] == 'L':
            if cursor > 0:
                cursor -= 1
                dq.appendleft(dq.pop())
        elif c[0] == 'D':
            if cursor < len(dq):
                cursor += 1
                dq.append(dq.popleft())
        elif c[0] == 'B':
            if len(dq) > 0 and cursor > 0:
                dq.pop()
                cursor -= 1
        else:
            a, b = c.split()
            dq.append(b)
            cursor += 1

    while 0 < cursor:
        cursor -= 1
        dq.appendleft(dq.pop())

    return ''.join(dq)


if __name__ == '__main__':
    content = readline().replace('\n', '')

    M = int(readline())

    command = [readline().replace('\n', '') for _ in range(M)]

    print(step1(content, M, command))
