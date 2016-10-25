import sys

x = [0]*3
y = [0]*3

x[0],y[0] = map(int, sys.stdin.readline().split())
x[1],y[1] = map(int, sys.stdin.readline().split())
x[2],y[2] = map(int, sys.stdin.readline().split())

x.sort()
y.sort()

ansX = 0
ansY = 0

if x[0]==x[1] :
	ansX = x[2]
else:
	ansX = x[0]

if y[0]==y[1] :
	ansY = y[2]
else:
	ansY = y[0]

print ('{0} {1}'.format(ansX, ansY))


