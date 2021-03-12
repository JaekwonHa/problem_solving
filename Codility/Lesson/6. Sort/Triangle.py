def solution(A):
    # write your code in Python 3.6
    if len(A) < 3:
        return 0
    sorted_A = sorted(A)
    for i in range(2, len(A)):
        if sorted_A[i] <= 0:
            continue
        if sorted_A[i-2] + sorted_A[i-1] > sorted_A[i]:
            return 1
    return 0