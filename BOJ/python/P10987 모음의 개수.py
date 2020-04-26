str = input()

ans = 0

for a in str:
	if a=='a' or a=='e' or a=='i' or a=='u' or a=='o':
		ans = ans + 1

print (ans)