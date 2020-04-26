import sys

n,m = map(int, sys.stdin.readline().split())

DP = [[-1]*(m+1) for i in range(n+1)]

def comb(n,m):
	if DP[n][m]!=-1:
		return DP[n][m]
	if n==m:
		return 1
	if m==1:
		return n
	DP[n][m] = comb(n-1,m-1) + comb(n-1,m)
	return DP[n][m]

print(comb(n,m))