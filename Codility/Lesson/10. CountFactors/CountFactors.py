# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import math

def solution(N):
    # write your code in Python 3.6
    if N <= 1:
        return N
    answer = 1
    for i in range(2, math.ceil(N**0.5)):
        if N % i == 0:
            answer += 1

    answer *= 2
    if (N**0.5) % 1 == 0:
        answer += 1

    return answer