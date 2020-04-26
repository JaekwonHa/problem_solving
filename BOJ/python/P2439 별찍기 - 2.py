import sys

n = int(sys.stdin.readline())

str2 = ' '
str1 = '*'

for i in range(0,n):
	str2 += ' '

for i in range(1,n):
	print (str2[1:n-i]),
	print (str1)
	str1 += '*'
print (str1)