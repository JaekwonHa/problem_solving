def solution(A):
    # write your code in Python 3.6
    if len(A) == 0:
        return 0

    K = [0] * len(A)
    K[0] = A[0]
    answer = K[0]
    for i in range(1, len(A)):
        K[i] = max(K[i-1]+A[i], A[i])
        answer = max(answer, K[i])

    return answer