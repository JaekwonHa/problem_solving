#include <stdio.h>

int N,n;
long long table[101];

void solve() {
	table[1]=1, table[2]=1, table[3]=1, table[4]=2, table[5]=2;
	
	for(int i=6, j=1, k=5; i<=100; i++,j++,k++) {
		table[i]=table[j]+table[k];
	}
}

int main() {

	scanf("%d", &N);
	
	solve();
	for(int i=0; i<N; i++) {
		scanf("%d", &n);
		printf("%lld\n", table[n]);
	}

	return 0;
}