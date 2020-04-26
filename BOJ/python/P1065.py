import sys



def run(N):
	answer = 0
	#N = int(sys.stdin.readline())

	if N<100:
		answer = N
		#print (answer)
	else:
		answer = 99
		ok = False

		for i in range(100, min(1000,N+1), 1):
			n1 = int(i/100)
			n2 = int((i/10)%10)
			n3 = int(i%10)
			if n1 - n2 == n2 - n3 :
				answer += 1

		"""
		for i in range(1,int(N/100)+1,1):

			for j in range(-1,-int(i/2+1),-1):
				number = i*100 + (i*10+j) + (i+j*2)
				if number <= int(N) :
					answer += 1

			for j in range(0,int((9-i)/2)+1,1):
				number = i*100 + (i*10+j) + (i+j*2)
				if number <= int(N) :
					answer += 1
		"""
		#print(answer)
	return answer

if __name__ == '__main__':
	N = 0
	if len(sys.argv) != 2 :
		N = int(sys.stdin.readline())
	else :
		N = int(sys.argv[1])
	print(run(N))