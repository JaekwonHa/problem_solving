import sys

sum = 0;

for a in sys.stdin.readline().split():
	sum += int(a)*int(a)

print(sum%10)

