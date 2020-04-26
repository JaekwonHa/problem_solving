#include <iostream>
#include <algorithm>
using namespace std;

#define p 10007

long long fac[1001];
int DP[1001][1001];

void factorial() {
	int i,num=1;
	for(int i=1; i<=1000; i++) {
		num = num*i%p;
		fac[i]=num;
	}
}

int f(int n, int k) {
	return ( 2*(fac[n-1]/(fac[n-k-1]*fac[k-1]))%p ) / ((n-k)*k);
}

int f2(int n, int k) {
	if(n==k) return 1;
	if(k==0) return 1;

	int& ret = DP[n][k];
	if(ret!=0) return ret;

	return ret=(f2(n-1,k)+f2(n-1,k-1))%p;
}

int main() {
	factorial();

	int N,K;
	scanf("%d %d", &N, &K);
	printf("%d\n", f2(N,K));


	return 0;
}