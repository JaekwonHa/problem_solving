import sys

readline = sys.stdin.readline


if __name__ == '__main__':
    command = readline().replace('\n', '')

    symbol = ['*', '+', '-', '/', '(', ')']

    st = []
    for i in range(len(command)):
        if command[i] not in symbol:
            print(command[i], end='')
            continue
        if len(st) == 0:
            st.append(command[i])
            continue

        if command[i] == '*':
            while len(st) > 0:
                if st[-1] in ['*', '/']:
                    print(st.pop(), end='')
                else:
                    break
            st.append('*')
        elif command[i] == '/':
            while len(st) > 0:
                if st[-1] in ['*', '/']:
                    print(st.pop(), end='')
                else:
                    break
            st.append('/')
        elif command[i] == '+':
            while len(st) > 0:
                if st[-1] in ['*', '/', '-', '+']:
                    print(st.pop(), end='')
                else:
                    break
            st.append('+')
        elif command[i] == '-':
            while len(st) > 0:
                if st[-1] in ['*', '/', '-', '+']:
                    print(st.pop(), end='')
                else:
                    break
            st.append('-')
        elif command[i] == '(':
            st.append('(')
        else:
            while len(st) > 0:
                if st[-1] != '(':
                    print(st.pop(), end='')
                else:
                    st.pop()
                    break

    while len(st) > 0:
        print(st.pop(), end='')
