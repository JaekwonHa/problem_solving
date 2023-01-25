import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    T = int(readline())
    for _ in range(T):
        N = int(readline())
        lamp = readline().replace('\n', '')

        answer = None
        for i in range(N-1):
            if lamp[i:i+2] == 'RL':
                answer = 0
                break
            elif lamp[i:i+2] == 'LR':
                answer = i+1
                break
        if answer is None:
            answer = -1

        print(answer)

