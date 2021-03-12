# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    partial_sum = [A[0]]
    for i in range(1, len(A)):
        partial_sum.append(partial_sum[i - 1] + A[i])

    # print("partial_sum[-1]: ", partial_sum[-1])
    answer = 0
    for i in range(len(A)):
        if A[i] == 0:
            answer += (partial_sum[-1] - partial_sum[i])
            if answer > 1000000000:
                return -1
    return answer