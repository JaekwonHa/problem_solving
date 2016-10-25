#include <stdio.h>

int N,DT[31];

void solve() {

	DT[0]=1,DT[2]=3;
	for(int i=4; i<=N; i+=2) {
		DT[i]=DT[i-2]*3;
		for(int j=i-4; j>=0; j-=2) {
			DT[i] += DT[j]*2;
		}
	}

}

int main() {

	scanf("%d", &N);

	solve();

	printf("%d", DT[N]);

	return 0;
}