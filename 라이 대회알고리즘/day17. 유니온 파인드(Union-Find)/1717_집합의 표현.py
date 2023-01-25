import sys
readline=sys.stdin.readline


def find(n: int):
    global p
    if p[n] < 0:
        return n
    p[n] = find(p[n])
    return p[n]


def merge(a: int, b: int):
    global p
    a = find(a)
    b = find(b)
    if a == b:
        return
    p[b] = a


if __name__ == '__main__':
    N, M = map(int, readline().split())

    p = [-1 for _ in range(N+1)]

    for _ in range(M):
        a, b, c = map(int, readline().split())
        if a == 0:
            merge(b, c)
        else:
            if find(b) == find(c):
                print("YES")
            else:
                print("NO")
