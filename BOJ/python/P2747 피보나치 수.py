import sys

n = int(sys.stdin.readline())
DP = [-1]*(n+1)

def fibo(n):
	if DP[n]!=-1:
		return DP[n]
	if n<=0:
		return 0
	if n<=2:
		return 1
	DP[n] = fibo(n-1)+fibo(n-2)
	return DP[n]

print (fibo(n))