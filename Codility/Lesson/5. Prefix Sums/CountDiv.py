def solution(A, B, K):
    # write your code in Python 3.6
    a = A if A%K == 0 else A + (K-(A%K))
    b = B if B%K == 0 else B - (B%K)
    return int((b-a)/K) + 1