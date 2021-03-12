# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    start_hash = {}
    end_hash = {}
    for a in A:
        end_hash.setdefault(a, 0)
        end_hash[a] = end_hash[a] + 1
    answer = 0
    for i in range(len(A)):

        start_hash.setdefault(A[i], 0)
        start_hash[A[i]] = start_hash[A[i]] + 1
        end_hash[A[i]] = end_hash[A[i]] - 1
        start_max = find_leader(start_hash, i+1)
        end_max = find_leader(end_hash, len(A)-i-1)
        # print(*(start_hash.values()), sep = ", ")
        # print(*(end_hash.values()), sep = ", ")
        # print("start_max: ", start_max)
        # print("end_max: ", end_max)
        if start_max != -1 and start_max == end_max:
            answer += 1
    return answer


def find_leader(H, length):
    for k, v in H.items():
        if v*2 > length:
            return k
    return -1