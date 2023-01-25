import sys
readline=sys.stdin.readline


def step1(N, P, input):
    st = [[0] for _ in range(7)]

    answer = 0
    for line, fret in input:
        if len(st[line]) == 0:
            answer += 1
            st[line].append(fret)
            continue
        if st[line][-1] == fret:
            continue
        if st[line][-1] < fret:
            answer += 1
            st[line].append(fret)
            continue
        while st[line][-1] > fret:
            answer += 1
            st[line].pop()
        if st[line][-1] == fret:
            continue
        answer += 1
        st[line].append(fret)

    return answer


if __name__ == '__main__':
    N, P = map(int, readline().split())

    input = [tuple(map(int, readline().split())) for _ in range(N)]

    print(step1(N, P, input))
