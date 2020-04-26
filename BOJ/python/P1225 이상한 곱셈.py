import sys

S = sys.stdin.readline().split()

answer = 0
b = 0
for j in range(0,len(S[1])):
	b += int(S[1][j])

for i in range(0,len(S[0])):
	a = int(S[0][i])
	answer += a*b

print(answer)