import sys
from collections import deque

readline=sys.stdin.readline

if __name__ == '__main__':
    T = int(readline())

    for _ in range(T):
        command = readline().replace('\n', '')
        N = int(readline())
        input = readline().replace('\n', '')
        q = deque([])
        if N != 0:
            q = deque(list(map(int, input[1:-1].split(','))))

        direction = 0
        for i in range(len(command)):
            if command[i] == 'R':
                if direction == 0:
                    direction = -1
                else:
                    direction = 0
                continue
            if len(q) == 0:
                print("error")
                break
            if direction == -1:
                q.pop()
            else:
                q.popleft()
        else:
            if direction == 0:
                print(f"[{','.join(map(str, q))}]")
            else:
                q.reverse()
                print(f"[{','.join(map(str, q))}]")


