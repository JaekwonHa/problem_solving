import sys
readline=sys.stdin.readline




if __name__ == '__main__':
    A, B = map(int, readline().split())
    one = set(list(map(int, readline().split())))
    two = set(list(map(int, readline().split())))

    minus = len(one.intersection(two))

    print(A+B-(2*minus))
