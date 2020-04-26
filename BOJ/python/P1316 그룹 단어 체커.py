import sys

N = int(input())

answer = 0

for i in range(0,N):
	s = input()
	chk = [0]*[ord('z')+1]
	isAnswer = 0
	for j in range(0,len(s)):
		if chk[s[j]] == 0:
			chk[s[j]] = 1
		else:
			isAnswer = 1
			break
	if isAnswer == 0:
		answer += 1
print(answer)