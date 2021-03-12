# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(X, A):
    # write your code in Python 3.6
    hash = {}
    for i in range(len(A)):
        if A[i] <= X:
            hash[A[i]] = True
        if len(hash) == X:
            return i
    return -1
