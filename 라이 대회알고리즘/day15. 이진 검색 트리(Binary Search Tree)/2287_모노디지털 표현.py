import sys
readline=sys.stdin.readline


if __name__ == '__main__':
    K = int(readline())

    cache = {}

    # 가능한 연산이 총 5가지

    temp = 0
    for i in range(1, 9):
        temp = temp*10 + K
        cache[i] = [temp]

    for i in range(1, 9):
        for j in range(1, 9):
            if i + j > 8:
                break
            for first in cache[i]:
                for second in cache[j]:
                    # 더하기
                    cache[i+j].append(first + second)
                    # 뺴기
                    if first != second:
                        cache[i+j].append(max(first, second) - min(first, second))
                    # 곱하기
                    cache[i+j].append(first * second)
                    # 나누기
                    cache[i+j].append(max(first, second) // min(first, second))

    N = int(readline())
    for _ in range(N):
        number = int(readline())

        find = False
        for i in range(1, 9):
            for answer in cache[i]:
                if answer == number:
                    print(i)
                    find = True
                    break
            if find:
                break
        if not find:
            print("NO")
