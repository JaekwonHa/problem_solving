# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    l = len(A)
    hash = {}
    for i in range(l):
        hash.setdefault(A[i], 0)
        hash[A[i]] = hash[A[i]] + 1
        if hash[A[i]] * 2 > l:
            return i
    return -1