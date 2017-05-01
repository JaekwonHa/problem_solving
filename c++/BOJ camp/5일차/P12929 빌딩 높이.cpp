#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int N, K, M, X[501], T[501];
	scanf("%d %d %d", &N, &K, &M);
	for (int i = 0; i < M; i++) scanf("%d", &X[i]);
	for (int i = 0; i < M; i++) scanf("%d", &T[i]);

	long long ans = 0, dist,m;
	long long start = 1, end = 0;
	long long startH = 0, endH = 0;
	for (int i = 0; i < M; i++) {
		end = X[i];
		endH = T[i];
		m = ((end - start) / 2)*K;
		ans = max(ans, m);
		start = end;
		startH = endH;
	}
	end = N;
	m = ((end - start) / 2)*K;
	ans = max(ans, m);

	printf("%lld\n", ans);

	return 0;
}

