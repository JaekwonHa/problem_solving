from subprocess import call
import P1065, P1065_2

for i in range(1,1001):
	ret1 = P1065.run(i)
	ret2 = P1065_2.run(i)
	if ret1 != ret2 :
		print (str(i) + "에서 답이 " + str(ret1) + " / " + str(ret2))


