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

int N, K;
ll DP[51][51][51];
vector<int> g[51];
vector<int> tree[51];

void dfs(int n, int parent) {
	for (int x : g[n]) {
		if (x == parent) continue;
		tree[n].push_back(x);
		dfs(x, n);
	}
}

ll f(int n, int k, int e) {
	ll &ret = DP[n][k][e];
	if (ret != -1) return ret;
	if (k == 0) return 1;
	if (e == tree[n].size()) {
		return k == 1 ? 1 : 0;
	}

	ret = 0;
	for (int i = 0; i < k; i++) {
		ll t1 = f(n, k - i, e + 1);
		ll t2 = f(tree[n][e], i, 0);
		ret += (t1*t2) % p;
	}
	ret %= p;
	return ret;
}

int main() {

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N-1; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		g[from].push_back(to);
		g[to].push_back(from);
	}

	// make tree
	dfs(1, 1);
	memset(DP, -1, sizeof(DP));
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += f(i, K, 0);
		ans %= p;
	}

	printf("%lld", ans);

	return 0;
}


