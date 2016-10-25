import sys

list = []

for a in sys.stdin.readline().split():
	list.append(int(a))

list.sort()

print(list[1])