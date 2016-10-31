#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define p 1000000007

int N;
long long DP[101][101][101];

long long f(int n, int l, int r) {
	if(n<0 || l<0 || r<0) return 0;

	long long &ret = DP[n][l][r];
	if(ret!=-1) return DP[n][l][r];

	ret = ((n-2)*f(n-1,l,r) + f(n-1,l-1,r) + f(n-1,l,r-1))%p;

	return ret;
}

int main() {
	memset(DP,-1,sizeof(DP));
	int l,r;
	scanf("%d %d %d", &N, &l, &r);

	DP[1][1][1]=1;
	printf("%d\n", f(N,l,r));


	return 0;
}