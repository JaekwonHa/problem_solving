import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    M = int(readline())

    storage = 0
    for _ in range(M):
        command: str = readline().replace('\n', '')

        if command.startswith('add'):
            storage |= (1 << int(command.split()[1]))
        elif command.startswith('remove'):
            storage &= ~(1 << int(command.split()[1]))
        elif command.startswith('check'):
            result = storage & (1 << int(command.split()[1]))
            if result != 0:
                print(1)
            else:
                print(0)
        elif command.startswith('toggle'):
            storage ^= (1 << int(command.split()[1]))
        elif command.startswith('all'):
            storage = (1 << 21)-1
        else:
            storage = 0
