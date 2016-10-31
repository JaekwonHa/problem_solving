#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;

int N, K;
long long P[100001];
long long DP[100001][51];
long long ans;

long long combi(int n, int k) {
	if (n == k) return 1;
	if (k == 0) return 1;

	long long &ret = DP[n][k];
	if (ret != -1) return ret;

	ret = (combi(n - 1, k) + combi(n - 1, k - 1)) % p;
}

int main() {

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &P[i]);

	sort(P, P + N + 1, [](long long a, long long b) {
		return a > b;
	});
	memset(DP, -1, sizeof(DP));
	for (int i = 0; i < N-K+1; i++) {
		ans = (ans + (P[i] * combi(N - i - 1, K - 1))%p)%p;
	}

	printf("%lld\n", ans);

	return 0;
}