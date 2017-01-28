import sys

N = int(sys.stdin.readline())
F = int(sys.stdin.readline())

answer = 100

for i in range(0, 100):
	number = int(N/100)*100 + i
	if number % F == 0:
		answer = min(answer, i)

print ('%02d' % answer)