import sys

n = int(sys.stdin.readline())

list = [0]*n

for i in range(0,n):
	list[i] = int(sys.stdin.readline())

list.sort()
#list.reverse()

for i in range(0,n):
	print (list[i])