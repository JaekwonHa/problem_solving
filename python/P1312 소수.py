import sys

A,B,N = map(int,sys.stdin.readline().split())

answer = 0
A %= B
for i in range(0,N):
    A *= 10
    if A == 0:
        answer = 0
        break
    else:
        answer = A/B
        A %= B
print(int(answer))