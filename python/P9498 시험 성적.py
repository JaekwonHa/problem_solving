import sys

n = int(sys.stdin.readline())

ans = ''

if n >= 90 :
	ans = 'A'
elif n >= 80 :
	ans = 'B'
elif n >= 70 :
	ans = 'C'
elif n >= 60 :
	ans = 'D'
else :
	ans = 'F'

print (ans)