#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int DP[1 << 20][20];
int W[20][20];

int main() {

	int N, a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	for (int i = 0; i<(1 << N); i++) {
		for (int j = 0; j<N; j++) {
			DP[i][j] = 100000000;
		}
	}
	DP[1][0] = 0;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 1; j < N; j++) {
			if (i&(1 << j)) {
				for (int k = 0; k < N; k++) {
					if ((i&(1 << k)) && W[j][i] != 0 && j != k) {
						DP[i][j] = min(DP[i][j], DP[i&~(1<<j)][k] + W[k][j]);
					}
				}
			}
		}
	}
	int ans = 100000000;
	for (int i = 1; i < N; i++) {
		if (W[i][0]) {
			ans = min(ans, DP[(1<<N)-1][i]+W[i][0]);
		}
	}
	printf("%d\n", ans);

	return 0;
}

