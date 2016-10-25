#include <stdio.h>
#define MAX 1000000

int N;
long long DT[100][2];
long long DT2[100];

long long zeroCount[MAX];
long long oneCount[MAX];

long long f(int n, int x) {
	if(n<=1) return 1;
	if(DT[n][x]!=0) return DT[n][x];

	if(x==0) {
		long long one, zero;

		if(DT[n-1][0]==0) zero=DT[n-1][0]=f(n-1,0);
		else zero = DT[n-1][0];

		if(DT[n-1][1]==0) one=DT[n-1][1]=f(n-1,1);
		else one = DT[n-1][1];

		DT[n][x]=one+zero;
	} else {
		long long zero;

		if(DT[n-1][0]==0) zero=DT[n-1][0]=f(n-1,0);
		else zero = DT[n-1][0];

		DT[n][x] = zero;
	}
	return DT[n][x];
}
void f2(int n, int x) {
	if(n>N) return;

	DT2[n]++;

	if(x==1) {
		f2(n+1, 0);
	} else {
		f2(n+1, 1);
		f2(n+1, 0);
	}
}

int main() {

	scanf("%d", &N);

	//f2(0,1);

	//printf("%lld", DT2[N]);

	printf("%lld", f(N,1));

	/*
	zeroCount[1]=0;
	oneCount[1]=1;
	zeroCount[2]=1;
	oneCount[2]=0;

	for(int i=3; i<=N; i++) {
		zeroCount[i] = zeroCount[i-1] + oneCount[i-1];
		oneCount[i] = zeroCount[i-1];
	}

	printf("%lld\n", zeroCount[N]+oneCount[N]);
	*/
	return 0;
}