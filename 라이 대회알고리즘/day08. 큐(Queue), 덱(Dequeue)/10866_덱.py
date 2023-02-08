import sys
from collections import deque

readline=sys.stdin.readline


if __name__ == '__main__':
    N = int(readline())

    q = deque([])

    for _ in range(N):
        command = readline().replace('\n', '')
        if command == "pop_front":
            print(q.popleft() if len(q) != 0 else "-1")
        elif command == "pop_back":
            print(q.pop() if len(q) != 0 else "-1")
        elif command == "size":
            print(len(q))
        elif command == "empty":
            print(1 if len(q) == 0 else 0)
        elif command == "front":
            print(q[0] if len(q) != 0 else -1)
        elif command == "back":
            print(q[-1] if len(q) != 0 else -1)
        else:
            command, number = command.split()[0], int(command.split()[1])
            if command == "push_front":
                q.appendleft(number)
            else:
                q.append(number)
