#include <stdio.h>

int T,N;
long long DT[68];

void solve() {
	for(int i=4; i<=67; i++) {
		DT[i]=DT[i-1]+DT[i-2]+DT[i-3]+DT[i-4];
	}
}

int main() {
	
	DT[0]=1,DT[1]=1,DT[2]=2,DT[3]=4;
	solve();

	scanf("%d", &T);
	for(int i=0; i<T; i++) {
		scanf("%d", &N);
		printf("%lld\n", DT[N]);
	}
	return 0;
}