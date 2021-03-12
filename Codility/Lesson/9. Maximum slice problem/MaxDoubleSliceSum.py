def solution(A):
    # write your code in Python 3.6
    partial_sum = [A[0]]
    for i in range(1, len(A)):
        partial_sum.append(partial_sum[i-1] + A[i])

    answer = -987654321

    # for i in range(len(A)-2):
    #     for j in range(i+1, len(A)-1):
    #         for k in range(j+1, len(A)):
    #             answer = max(answer, partial_sum[k]-A[k]-A[j]-partial_sum[i])

    # for j in range(1, len(A)-1):
    #     left_sum, right_sum = -987654321, -987654321
    #     for i in range(0, j):
    #         left_sum = max(left_sum, partial_sum[j]-A[j]-partial_sum[i])
    #     for k in range(j+1, len(A)):
    #         right_sum = max(right_sum, partial_sum[k]-A[k]-partial_sum[j])
    #     answer = max(answer, left_sum + right_sum)

    left_sum = [0]*len(A)
    right_sum = [0]*len(A)
    for i in range(1, len(A)):
        left_sum[i] = max(0, left_sum[i-1]+A[i])
    for i in range(len(A)-2, 1, -1):
        right_sum[i] = max(0, right_sum[i+1]+A[i])
    for j in range(1,len(A)-1):
        answer = max(answer, left_sum[j-1]+right_sum[j+1])

    return answer