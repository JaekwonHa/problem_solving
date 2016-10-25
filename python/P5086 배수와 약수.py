import sys

while True:
	a,b = map(int, sys.stdin.readline().split())
	if a==0 and b==0:
		break
	ans = ""
	if b%a==0:
		ans = "factor"
	elif a%b==0:
		ans = "multiple"
	else:
		ans = "neither"
	print(ans)