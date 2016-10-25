#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, K, W[110], V[110];
int DP[110][100010];

int main() {

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= K; k++) {
			if (W[i] > k) {
				DP[i][k] = DP[i - 1][k];
			}
			else {
				DP[i][k] = max(DP[i - 1][k], DP[i - 1][k - W[i]] + V[i]);
			}
		}
	}

	printf("%d\n", DP[N][K]);


	return 0;
}
