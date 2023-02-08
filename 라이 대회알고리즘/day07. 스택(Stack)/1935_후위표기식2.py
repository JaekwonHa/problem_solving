import sys
readline=sys.stdin.readline



if __name__ == '__main__':
    N = int(readline())

    content = readline().replace('\n', '')

    m = {}
    for i in range(N):
        a = int(readline())
        # content = content.replace(str(chr(0x41 + i)), str(a))
        m[str(chr(0x41 + i))] = a

    symbol = ['*', '+', '-', '/']
    st = []
    for i in range(len(content)):
        if content[i] in symbol:
            b = st.pop()
            a = st.pop()
            if content[i] == '*':
                st.append(a*b)
            elif content[i] == '/':
                st.append(a/b)
            elif content[i] == '+':
                st.append(a+b)
            else:
                st.append(a-b)
            continue
        st.append(int(m[content[i]]))

    print("{:.2f}".format(st[-1]))

