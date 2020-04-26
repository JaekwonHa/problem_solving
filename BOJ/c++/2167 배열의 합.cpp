#include <stdio.h>

int N,M,K;
unsigned int DT[302][302][302];
int ki[10001], kj[10001], kx[10001], ky[10001], ans[10001];

void init() {
	for(int i=1; i<=300; i++) {
		for(int j=1; j<=300; j++) {
			for(int k=2; j+k<=300; k++) {
				DT[i][j][k] = DT[i][j][k-1]+DT[i][j+k-1][1];
			}
		}
	}
}
void solve() {
	for(int i=0; i<K; i++) {
		int step = ky[i]-kj[i]+1;
		for(int j=ki[i]; j<=kx[i]; j++) {
			ans[i] += DT[j][kj[i]][step];
		}
	}
}
void solve2() {
	for(int k=0; k<K; k++) {
		for(int i=ki[k]; i<=kx[k]; i++) {
			for(int j=kj[k]; j<=ky[k]; j++) {
				ans[k] += DT[i][j][1];
			}
		}
	}
}

int main() {


	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d", &DT[i][j][1]);
	scanf("%d", &K);
	for(int i=0; i<K; i++)
		scanf("%d %d %d %d", &ki[i], &kj[i], &kx[i], &ky[i]);
	
	init();
	solve();
	//solve2();

	for(int i=0; i<K; i++) {
		printf("%d\n", ans[i]);
	}


	return 0;
}