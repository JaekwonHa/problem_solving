import math

N = int(input())
n = list(map(int, input().split()))

Y = 0
M = 0

for i in range(0,len(n)):
	Y += math.ceil(n[i]/30)*10
	M += math.ceil(n[i]/60)*15

if Y <= M:
	print("Y %d" % (Y))
if M <= Y:
	print("M %d" % (M))