import sys
readline=sys.stdin.readline



if __name__ == '__main__':
    N = int(readline())

    answer = 0
    i = 1
    while i <= N:
        number = (N-1) // i
        remain = (N-1) % i
        d = remain // number +1 if remain > 0 and number > 0 else 1
        answer += (number+1) * d
        i += d

    # number에 +1을 안해줄꺼라면 최종 답에 +N 을 해줘야한다
    print(answer)
