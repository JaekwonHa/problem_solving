#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define p 1000000000
#define MAXN 1000010

int N,DP[MAXN];

int f(int n) {
	DP[0]=1;
	int i,coin=1;
	for(i=1; coin<=n; i++) {
		coin *= 2;
	}
	coin /= 2;
	i--;

	for(; coin>0; i--) {
		for(int j=coin; j<=n; j++) {
			DP[j] = (DP[j]+DP[j-coin])%p;
		}
		coin /= 2;
	}
	return DP[n];
}

int main() {
	memset(DP,0,sizeof(DP));
	scanf("%d", &N);

	printf("%d\n", f(N));

	return 0;
}