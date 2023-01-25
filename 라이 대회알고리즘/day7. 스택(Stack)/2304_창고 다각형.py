import sys
readline=sys.stdin.readline


def step1(N, block):
    st = []
    answer = 0
    for i in range(N):
        if len(st) == 0:
            st.append(i)
            continue
        if block[i][1] <= block[st[0]][1]:
            st.append(i)
            continue

        height = block[st[0]][1]
        width = block[i][0] - block[st[0]][0]
        answer += height * width

        st.clear()
        st.append(i)

    while len(st) != 0:
        i, height = block[st.pop()]
        if len(st) == 0:
            answer += height
            continue
        prev = 0
        while len(st) != 0 and block[st[-1]][1] < height:
            prev, _ = block[st.pop()]
        width = i - block[st[-1]][0]
        answer += height * width

    return answer


if __name__ == '__main__':
    N = int(readline())
    block = [tuple(map(int, readline().split())) for _ in range(N)]
    block.sort()

    print(step1(N, block))
