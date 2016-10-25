#include <stdio.h>

int N,M,map[1010][1010];
long long DT[1010][1010];

long long max(long long a, long long b) { return (a>b)?a:b;}

long long f(int n, int m) {

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			long long cost = max(DT[i-1][j], DT[i-1][j-1]);
			cost = max(cost, DT[i][j-1]);
			cost += map[i][j];
			DT[i][j] = cost;
		}
	}
	return DT[n][m];
}

int main() {


	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d", &map[i][j]);

	printf("%lld", f(N,M));

	return 0;
}