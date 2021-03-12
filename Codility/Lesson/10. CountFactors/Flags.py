# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

# def solution(A):
#     # write your code in Python 3.6
#     answer = 0
#     for k in range(1, int(len(A)/2)+1):
#         flag = 0
#         last_peek = 0
#         for i in range(1, len(A)-1):
#             if last_peek != 0 and i-last_peek < k:
#                 continue
#             if A[i-1] < A[i] and A[i] > A[i+1]:
#                 flag += 1
#                 last_peek = i
#                 # print("k:", k, "i:", i, "flag: ", flag)
#             if k == flag:
#                 break
#         if answer > flag:
#             return answer
#         answer = flag
#     return answer

def solution(A):
    # write your code in Python 3.6

    peeks = []
    for i in range(1, len(A)-1):
        if A[i-1] < A[i] and A[i] > A[i+1]:
            peeks.append(i)

    answer = 0
    for k in range(1, len(peeks)+1):
        flag = 0
        last_peek = 0
        for i in peeks:
            if last_peek != 0 and i-last_peek < k:
                continue
            flag += 1
            last_peek = i
            # print("k:", k, "i:", i, "flag: ", flag)
            if k == flag:
                break
        if answer > flag:
            return answer
        answer = flag
    return answer