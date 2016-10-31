#include <stdio.h>
#include <algorithm>
#include <string.h>

int K,C,M,N,DT[1001][1001];

void solve() {
	for(int i=0; i<=K; i++) {
		for(int j=0; j<=K; j++) {
			//if(i+(K-std::max(i,j))<j || j+(K-std::max(i,j))<i) {
			if(i+(K-std::max(i,j))<j) {
				DT[i][j]=1;
				break;
			} else
				DT[i][j]=1;
		}
	}
	for(int j=0; j<=K; j++) {
		for(int i=0; i<=K; i++) {
			//if(i+(K-std::max(i,j))<j || j+(K-std::max(i,j))<i) {
			if(j+(K-std::max(i,j))<i) {
				break;
			} else if(DT[i][j]==0)
				DT[i][j]=1;
		}
	}
}

int main() {
	memset(DT,0,sizeof(DT));
	scanf("%d", &K);
	scanf("%d", &C);
	solve();
	while(C--) {
		scanf("%d %d", &M, &N);
		printf("%d\n", DT[M][N]);
	}

	return 0;
}