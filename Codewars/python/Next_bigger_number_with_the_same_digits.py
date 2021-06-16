import itertools


def next_bigger(n):
    n = list(str(n))
    i = len(n) - 1
    while i > 0 and n[i-1] >= n[i]:
        i += -1

    if i <= 0:
        return -1

    j = len(n) - 1
    while j > 0 and n[i-1] >= n[j]:
        j += -1

    temp = n[i-1]
    n[i-1] = n[j]
    n[j] = temp

    rev = n[i:]
    answer = n[:i] + rev[::-1]

    return int(''.join(answer))


print(next_bigger(513))
print(next_bigger(2017))
print(next_bigger(144))
