def solution(A):
    # write your code in Python 3.6
    sorted_A = sorted(A)
    a = sorted_A[-1] * sorted_A[-2] * sorted_A[-3]
    b = sorted_A[0] * sorted_A[1] * sorted_A[-1]
    return max(a,b)