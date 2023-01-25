import sys
readline=sys.stdin.readline

if __name__ == '__main__':
    N = int(readline())

    for i in range(N):
        print(sum(map(int, readline().split('+'))))
