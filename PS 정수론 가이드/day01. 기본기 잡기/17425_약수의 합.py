import sys

readline=sys.stdin.readline




if __name__ == '__main__':
    MAX = 1000001

    f1 = [1 for _ in range(MAX)]
    for i in range(2, MAX, 2):
        f1[i] += 2
    for i in range(3, MAX):
        for j in range(i, MAX, i):
            f1[j] += i

    f2 = [0 for _ in range(MAX)]
    for i in range(1, MAX):
        f2[i] = f1[i] + f2[i-1]

    for _ in range(int(readline())):
        N = int(readline())
        print(f2[N])
