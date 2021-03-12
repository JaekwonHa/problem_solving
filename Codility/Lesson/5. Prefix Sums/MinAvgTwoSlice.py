# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    partial_sum = [A[0]]
    for i in range(1, len(A)):
        partial_sum.append(partial_sum[i - 1] + A[i])

    # print("partial_sum:", partial_sum[-1])
    answer = 0
    min_average = 987654321
    for i in range(len(A) - 1):
        for j in range(i + 1, len(A)):
            a = 0 if i == 0 else partial_sum[i - 1]
            b = partial_sum[j]
            result = (b - a) / (j - i + 1)
            if result < min_average:
                min_average = result
                answer = i
    return answer