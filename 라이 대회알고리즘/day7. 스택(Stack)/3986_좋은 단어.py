import sys
readline=sys.stdin.readline


def step1(content):
    if len(content) % 2 == 1:
        return 0

    st = []
    for i in range(len(content)):
        if len(st) == 0:
            st.append(content[i])
            continue
        if st[-1] == content[i]:
            st.pop()
            continue
        st.append(content[i])

    return 1 if len(st) == 0 else 0


if __name__ == '__main__':
    N = int(readline())

    answer = 0
    for _ in range(N):
        answer += step1(readline().replace('\n', ''))

    print(answer)
