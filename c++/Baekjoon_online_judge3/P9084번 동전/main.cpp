#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10010

int T,N,M,DP[MAXN],coin[21];

int f(int m) {

	DP[0]=1;
	for(int i=N-1; i>=0; i--) {
		for(int j=coin[i]; j<=m; j++) {
			DP[j] += DP[j-coin[i]];
		}
	}

	return DP[m];
}

int main() {

	scanf("%d", &T);
	while(T--) {
		
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &coin[i]);
		scanf("%d", &M);
		
		fill(DP,DP+MAXN,0);
		printf("%d\n", f(M));
	}


	return 0;
}