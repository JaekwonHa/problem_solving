import sys

readline = sys.stdin.readline


if __name__ == '__main__':
    N = int(readline())

    st = []

    for _ in range(N):
        command = readline()

        if "push" in command:
            st.append(int(command.split()[1]))
        elif "pop" in command:
            print(st.pop() if len(st) != 0 else -1)
        elif "size" in command:
            print(len(st))
        elif "empty" in command:
            print(1 if len(st) == 0 else 0)
        else:
            print(st[-1] if len(st) != 0 else -1)

