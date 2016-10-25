#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 10010

int N,P[MAXN],DP[MAXN];

int f(int n) {
	for(int i=0; i<=n; i++) DP[i]=P[i];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			DP[i]=max(DP[i],DP[i-j]+P[j]);
		}
	}
	return DP[n];
}

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &P[i]);

	printf("%d", f(N));

	return 0;
}