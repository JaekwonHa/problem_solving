import sys

readline = sys.stdin.readline


if __name__ == '__main__':
    N = int(readline())

    for _ in range(N):
        command = readline().replace('\n', '')

        st = []
        for i in range(len(command)):
            if command[i] == '(':
                st.append('(')
            else:
                if len(st) > 0 and st[-1] == '(':
                    st.pop()
                else:
                    print("NO")
                    break
        else:
            print("YES" if len(st) == 0 else "NO")
