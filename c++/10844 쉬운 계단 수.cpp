#include <stdio.h>
#include <string.h>
#define p 1000000000

int N;
long long DT[101][10];

long long f(int n, int k) {
	if(k<0 || k>9) return 0;
	if(n==1 && k==0) return 0;
	if(n==1) return DT[1][k];
	
	long long ret = DT[n][k];
	if(ret != -1) return DT[n][k];
	ret =0;
	ret += f(n-1,k-1)%p;
	ret += f(n-1,k+1)%p;

	return DT[n][k]=ret%p;
}

int main() {
	memset(DT, -1, sizeof(DT));

	scanf("%d", &N);

	DT[1][0]=0;
	for(int i=1; i<=9; i++)
		DT[1][i]=1;

	long long ans = 0;
	for(int i=0; i<10; i++) {
		ans = (ans + f(N,i))%p;
	}
	
	printf("%lld", ans);

	return 0;
}