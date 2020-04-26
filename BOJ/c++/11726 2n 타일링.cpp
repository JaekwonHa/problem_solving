#include <stdio.h>
#define p 10007

int N,DT[1001];

void solve() {
	DT[0]=1;
	DT[1]=1;
	DT[2]=2;
	for(int i=3; i<=N; i++) {
		DT[i]=(DT[i-1]+DT[i-2])%p;
	}
}

int main() {

	scanf("%d", &N);

	solve();

	printf("%d", DT[N]);

	return 0;
}