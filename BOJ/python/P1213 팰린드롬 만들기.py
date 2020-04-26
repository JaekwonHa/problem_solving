S = input()
count = [0]*(ord('Z')+1)
for i in range(0,len(S)):
	count[ord(S[i])] += 1

pair = 0
odd = 0

pairList = []
oddList = []

for i in range(ord('A'), ord('Z')+1):
	if count[i] != 0 and count[i]%2 == 0:
		pair+=1
		for j in range(0,int(count[i]/2)):
			pairList.append(chr(i))
	elif count[i] != 0:
		odd+=1
		oddList.append(chr(i))
		for j in range(0,int(count[i]/2)):
			pairList.append(chr(i))

#print(pairList)
#print(oddList)		

if len(S)%2==0 and odd == 0:
	pairList.sort()
	answer = ''
	for i in range(0,len(pairList)):
		answer += pairList[i]
	pairList.reverse()
	for i in range(0,len(pairList)):
		answer += pairList[i]
	print(answer)
elif len(S)%2==1 and odd == 1:
	pairList.sort()
	answer = ''
	for i in range(0,len(pairList)):
		answer += pairList[i]
	answer += oddList[0]
	pairList.reverse()
	for i in range(0,len(pairList)):
		answer += pairList[i]
	print(answer)
else:
	print("I'm Sorry Hansoo")