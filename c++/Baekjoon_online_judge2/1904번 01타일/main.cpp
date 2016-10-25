#include <stdio.h>
#include <string.h>
#define p 15746

int N, DT[1000000];

int f(int n) {
	if(n==0) return DT[n];

	int ret = DT[n];
	if(ret != -1) return DT[n];
	
	if(n%2==0) {
		return DT[n] = (f(n/2)*f(n/2)%p + f(n/2-1)*f(n/2-1)%p)%p;
	} else {
		return DT[n] = (f(n/2)*f(n/2+1)%p + f(n/2-1)*f(n/2)%p)%p;
	}
}

int main() {
	memset(DT, -1, sizeof(DT));

	scanf("%d", &N);

	DT[0]=1, DT[1]=1, DT[2]=2;

	printf("%d", f(N));


	return 0;
}