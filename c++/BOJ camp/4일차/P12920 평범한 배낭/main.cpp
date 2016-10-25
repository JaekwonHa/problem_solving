#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>

#define MAXN 101000

int N, M, V[101], C[101], K[101];
int DP[101][10010];

int main() {

	scanf("%d %d", &N, &M);

	int i, j, k;
	for (i = 0, j = 0; i < N; i++) {
		int a, b, c;
		scanf("%d %d %d", &V[i], &C[i], &K[i]);
	}
	int DPNK;
	for (i = 0; i < N; i++) {
		for (j = V[i]; j <= M; j++) {
			DP[i][j] = std::max(DP[i - 1][j], DP[i][j - V[i]] + C[i]);
		}
	}

	printf("%d\n", DP[N-1][M]);

	return 0;
}