#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;


int main() {

	int K, X[100001], ans = 0;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", X + i);
		ans += X[i] / K;
		X[i] %= K;
	}

	int cnt = INF;
	sort(X, X + K);
	for (int i = 0; i < K; i++) {
		cnt = min(cnt, X[i] + K - i - 1);
	}
	printf("%d\n", ans + cnt);

	return 0;
}

