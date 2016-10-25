
str = input().split()
str.sort()
a = int(str[0])
b = int(str[1])
c = int(str[2])

ans = 0
for i in range(1,3):
	if str[i]==str[i-1]:
		ans = ans+1

if ans==2:
	ans = c*1000 + 10000
elif ans==1:
	ans = b*100 + 1000
else:
	ans = c*100

print(ans)