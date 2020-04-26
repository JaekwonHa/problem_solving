import sys

N = list(map(lambda x:int(x), sys.stdin.readline().split()))
N.sort()

#print(N)

answer = 987654321

def customAppend(list, n):
	temp = []
	for i in range(0,len(list)):
		temp.append(list[i])
	temp.append(n)
	return temp

def GCD(a, b):
	r = a%b
	while(r>0):
		a = b
		b = r
		r = a%b
	return b

def rec(n, cnt, numberList):

	global answer

	if cnt >= 3:
		temp = numberList[0]
		for i in range(1, cnt):
			temp = temp*numberList[i]/GCD(temp,numberList[i])
		answer = min(answer, temp)

	if n < 5:
		rec(n+1,cnt,numberList)
		rec(n+1,cnt+1,customAppend(numberList, N[n]))

rec(0,0,[])

print (int(answer))