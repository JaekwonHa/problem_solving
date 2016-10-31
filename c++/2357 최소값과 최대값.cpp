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

struct DATA {
	int minV, maxV;
	DATA(int a, int b) : minV(a), maxV(b) {};
	DATA() {};
};

int a[1000001];
DATA tree[3000001];

DATA init(int node, int s, int e) {
	if (s == e) {
		tree[node].minV = tree[node].maxV = a[s];
		return tree[node];
	}
	DATA t1 = init(node * 2, s, (s + e) / 2);
	DATA t2 = init(node * 2 + 1, (s + e) / 2 + 1, e);
	tree[node].minV = min(t1.minV, t2.minV);
	tree[node].maxV = max(t1.maxV, t2.maxV);
	return tree[node];
}

DATA minData(DATA t1, DATA t2) {
	DATA t3;
	t3.minV = min(t1.minV, t2.minV);
	t3.maxV = max(t1.maxV, t2.maxV);
	return t3;
}

DATA getMinMax(int node, int s, int e, int i, int j) {
	if (j < s || e < i) {
		DATA t1(INF, 0);
		return t1;
	}
	if (i <= s && e <= j) {
		return tree[node];
	}
	return minData(getMinMax(node * 2, s, (s + e) / 2, i, j), getMinMax(node * 2 + 1, (s + e) / 2 + 1, e, i, j));
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 3000000; i++) tree[i].minV = INF, tree[i].maxV = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	init(1, 0, n - 1);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (b < a) swap(a, b);
		a--, b--;
		DATA t1 = getMinMax(1, 0, n - 1, a, b);
		printf("%d %d\n", t1.minV, t1.maxV);
	}

	return 0;
}

