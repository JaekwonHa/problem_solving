# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import math

def solution(A):
    # write your code in Python 3.6
    hash = {}
    hash.setdefault(1, 0)
    for i in range(len(A)):
        hash.setdefault(A[i], 0)
        hash[A[i]] += 1

    # print(*(hash.keys()), sep = ", ")
    # print(*(hash.values()), sep = ", ")
    answer = []
    cache = {}
    for a in A:
        if a == 1:
            answer.append(len(A) - hash[1])
            continue

        if cache.get(a) is not None:
            answer.append(cache[a])
            continue

        divisor = hash[1] + hash[a]
        for i in range(2, math.ceil(a**0.5)):
            if a%i == 0:
                if hash.get(i) is not None:
                    # print("a: ", a, " i: ", i)
                    divisor += hash[i]
                if hash.get(int(a/i)) is not None:
                    # print("a: ", a, " i: ", int(a/i))
                    divisor += hash[int(a/i)]
        if a**0.5 % 1 == 0 and hash.get(int(a**0.5)) is not None:
            divisor += hash[int(a**0.5)]
        answer.append(len(A) - divisor)
        cache[a] = len(A) - divisor
    return answer