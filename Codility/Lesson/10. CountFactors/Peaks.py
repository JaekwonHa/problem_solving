# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    if len(A) <= 2:
        return 0

    peeks = []
    for i in range(1, len(A) - 1):
        if A[i - 1] < A[i] > A[i + 1]:
            peeks.append(i)

    K = []
    for i in range(1, len(A)):
        if len(A) % i == 0:
            K.append(i)

    answer = 0
    for k in K:
        count = int(len(A) / k)
        for i in range(k):
            find_peek = False
            for p in peeks:
                if i * count <= p < (i + 1) * count:
                    find_peek = True
                    break
            if find_peek is False:
                return answer
        answer = k
    return answer