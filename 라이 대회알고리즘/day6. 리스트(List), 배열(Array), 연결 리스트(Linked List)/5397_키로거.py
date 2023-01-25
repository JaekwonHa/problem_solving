import sys

readline = sys.stdin.readline

from collections import deque


def step1(command):
    dq = deque([])
    cursor = 0
    for i in range(len(command)):
        if command[i] == '<':
            if cursor > 0:
                cursor -= 1
                dq.appendleft(dq.pop())
        elif command[i] == '>':
            if cursor < len(dq):
                cursor += 1
                dq.append(dq.popleft())
        elif command[i] == '-':
            if len(dq) > 0 and cursor > 0:
                dq.pop()
                cursor -= 1
        else:
            dq.append(command[i])
            cursor += 1

    while 0 < cursor:
        cursor -= 1
        dq.appendleft(dq.pop())

    return ''.join(dq)


if __name__ == '__main__':
    T = int(readline())

    for _ in range(T):
        print(step1(readline().replace('\n', '')))
