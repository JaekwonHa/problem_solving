#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define p 1000000007

int N, K;
long long DP[11][100001];

long long f(int n, int k) {
	if (n == 0) return 1;

	long long &ret = DP[n][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i <= K; i++) {
		if (i <= k || (i/k)*k != i) {
			ret = (ret + f(n - 1, i)) % p;
		}
	}
	return ret;
}

int main() {

	
	scanf("%d %d", &N, &K);
	
	//memset(DP, -1, sizeof(DP));
	//printf("%lld\n", f(N, K));

	long long t;
	DP[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			
			DP[i][j] = DP[i-1][0];
			for (int k = 2; k*j <= K; k++) {
				if (DP[i][j] < DP[i-1][k*j]) DP[i][j] += p;
				DP[i][j] -= DP[i-1][k*j];
			}
			
			/*
			for (int k = 1; k <= K; k++) {
				if (j<=k && (j / k)*k == j) continue;
				DP[i][j] = (DP[i][j] + DP[i - 1][k]) % p;
			}
			*/
		}
		t = 0;
		for (int j = 1; j <= K; j++) {
			t = (t+DP[i][j])%p;
		}
		DP[i][0] = t;
	}
	printf("%lld\n", DP[N][0]);
	return 0;
}