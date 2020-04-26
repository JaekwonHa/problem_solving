#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 210
#define p 1000000000

int N,K,DP[MAXN][MAXN];

void solve() {
	for(int i=0; i<=N; i++) DP[i][1]=1;

	for(int i=2; i<=K; i++) {
		for(int j=0; j<=N; j++) {
			for(int k=0; j-k>=0; k++) {
				DP[j][i] = (DP[j][i]+DP[j-k][i-1])%p;
			}
		}
	}
}

int main() {

	scanf("%d %d",&N,&K);

	solve();

	printf("%d\n", DP[N][K]);

	return 0;
}