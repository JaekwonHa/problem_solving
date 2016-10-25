import sys

h,m = map(int, input().split())

plus = int(sys.stdin.readline())

g=0
m+=plus

if m>=60:
	g=m/60
	m=m-60*g;

h=h+g;

if h>=24:
	h=h-24;

print ('{0} {1}'.format(h, m))