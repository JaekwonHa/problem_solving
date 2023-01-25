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
    N = int(readline())
    M = int(readline())

    p = [-1 for _ in range(N+1)]
    for i in range(1, N+1):
        edges = list(map(int, readline().split()))
        for j in range(N):
            if edges[j] == 1:
                merge(i, j+1)

    cites = list(map(int, readline().split()))
    valid = True
    for i in range(len(cites)-1):
        if find(cites[i]) != find(cites[i+1]):
            valid = False
            break
    if valid:
        print("YES")
    else:
        print("NO")
   