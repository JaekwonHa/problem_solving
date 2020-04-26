
S = input().upper()

maxNumber1 = 1
maxNumber2 = 1
maxChr = S[0]

S = sorted(S)
#print(S)

for i in range(0,len(S)):
	#print('maxNumber1 : %d / maxNumber2 : %d' % (maxNumber1, maxNumber2))
	if i != len(S)-1 and S[i] == S[i+1]:
		maxNumber2+=1	
	elif maxNumber1 == maxNumber2:
		maxChr = '?'
		maxNumber2 = 1
	else:
		if maxNumber1 < maxNumber2:
			maxChr = S[i]
			maxNumber1 = maxNumber2
		maxNumber2 = 1

print(maxChr)