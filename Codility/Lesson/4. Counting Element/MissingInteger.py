def solution(A):
    # write your code in Python 3.6
    hash = {}
    for a in A:
        if a <= 0:
            continue
        hash.setdefault(a, 0)
        hash[a] += 1
    for i in range(1, len(A)+1):
        if hash.get(i) is None:
            return i
    return len(A)+1