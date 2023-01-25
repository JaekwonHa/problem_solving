import sys

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline


def find(n: int):
    global p
    if p[n] < 0:
        return n
    p[n] = find(p[n])
    return p[n]


def merge(a: int, b: int):
    global p, cost
    a = find(a)
    b = find(b)
    if a == b:
        return
    p[a] += p[b]
    p[b] = a


if __name__ == '__main__':
    T = int(readline())
    for _ in range(T):
        F = int(readline())
        edges = []
        name_dict = {}
        idx = 0
        p = [-1 for _ in range(200001)]
        for _ in range(F):
            a, b = readline().split()
            if name_dict.get(a) is None:
                name_dict[a] = idx
                idx += 1
            if name_dict.get(b) is None:
                name_dict[b] = idx
                idx += 1
            a_idx, b_idx = name_dict[a], name_dict[b]
            merge(a_idx, b_idx)
            print(-p[find(a_idx)])
