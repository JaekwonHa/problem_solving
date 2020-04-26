import sys

str = sys.stdin.readline().split()

list = [0]*3

list[0] = int(str[0])

list[1] = int(str[1])

list[2] = int(str[2])

list.sort()

ans = 0
while list[1]-list[0] != 1 or list[2]-list[1] != 1:
	if(list[1]-list[0] < list[2]-list[1]):
		list[0] = list[2]-1
	else:
		list[2] = list[0]+1
	list.sort()
	ans = ans + 1

print(ans)