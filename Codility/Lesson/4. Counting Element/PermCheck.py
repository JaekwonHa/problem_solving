def solution(A):
    # write your code in Python 3.6
    return 1 if len(set(A)) == len(A) and max(A) == len(A) else 0