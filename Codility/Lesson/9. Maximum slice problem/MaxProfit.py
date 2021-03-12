def solution(A):
    # write your code in Python 3.6
    if len(A)==0:
        return 0
    min_price = A[0]
    answer = 0
    for i in range(1, len(A)):
        min_price = min(min_price, A[i])
        answer = max(answer, A[i]-min_price)
    return answer