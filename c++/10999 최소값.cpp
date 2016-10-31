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

ll a[1000000];
ll tree[3000000];
ll init(int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s];
	return tree[node] = min(init(node * 2, s, (s + e) / 2), init(node * 2 + 1, (s + e) / 2 + 1, e));
}

ll getMin(int node, int s, int e, int i, int j) {
	if (j < s || e < i) {
		return INF;
	}
	if (i <= s && e <= j) {
		return tree[node];
	}
	return min(getMin(node * 2, s, (s + e) / 2, i, j), getMin(node * 2 + 1, (s + e) / 2 + 1, e, i, j));
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= 3000000; i++) tree[i] = INF;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	init(1, 0, n - 1);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		printf("%lld\n", getMin(1, 0, n - 1, a, b));
	}

	return 0;
}

