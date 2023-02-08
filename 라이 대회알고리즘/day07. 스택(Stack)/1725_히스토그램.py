import sys
readline=sys.stdin.readline




def step1(N, block):

    answer = 0
    block = [0, *block, 0]
    st = []

    for i in range(N+2):
        if len(st) == 0:
            st.append(i)
            continue
        if block[st[-1]] <= block[i]:
            st.append(i)
            continue
        while len(st) != 0 and block[st[-1]] > block[i]:
            idx = st.pop()
            answer = max(answer, ((i-1)-st[-1])*(block[idx]))
        st.append(i)

    # if len(st) != 0:
    #     i = N+1
    #     while len(st) != 0:
    #         answer = max(answer, (i-top)*(block[top]))
    #         top = st.pop()

    return answer


if __name__ == '__main__':
    N = int(readline())

    block = [int(readline()) for _ in range(N)]

    print(step1(N, block))
