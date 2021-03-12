# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N):
    # write your code in Python 3.6
    if N == 1:
        return 4

    answer = 987654321
    for i in range(2, int(N**0.5)+1):
        if N%i == 0:
            answer = min(answer, 2*(i+int(N/i)))
    return 2*(1+N) if answer == 987654321 else answer