import sys

a,b = map(int, input().split())

def power(n, exp) :
	ret = 1
	a = n
	while exp > 0 :
		if exp%2 == 1 :
			ret = ret * a

		a = a * a
		exp = int(exp/2)
	return ret

def power1(n, exp) :
	ret = n
	while exp > 1 :
		ret = ret * ret
		if exp%2 == 1 :
			ret = ret * n
		exp = int(exp/2)
	return ret


print (power(a,b))
print (power1(a,b))