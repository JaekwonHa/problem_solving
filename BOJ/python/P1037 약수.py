import sys

cnt = int(input())

list = []
for a in sys.stdin.readline().split():
	list.append(int(a))

list.sort()

print (list[0]*list[cnt-1])