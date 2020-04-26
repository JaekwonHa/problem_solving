N = int(input())
count = [0]*(ord('z')+1)
for i in range(0,N):
	s = input()
	count[ord(s[0])] += 1

check = False
for i in range(ord('a'), ord('z')+1):
	if count[i] > 4:
		check = True
		print(chr(i), end='')

if not check:
	print("PREDAJA")