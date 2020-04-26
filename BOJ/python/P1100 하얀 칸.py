answer = 0
for i in range(0,8):
	start = 0
	if i%2 == 1:
		start = 1
	line = input()
	for j in range(start,8,2):
		if line[j] == 'F':
			answer += 1
print(answer)
