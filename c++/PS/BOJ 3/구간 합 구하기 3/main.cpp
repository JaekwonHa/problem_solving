#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
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
#define mod 1000000007
typedef long long ll;

int n, m;
int a[1025][1025];
int tree[1025][1025];

void update(int x, int y, int val) {
	for (int i = x; i <= n; i += (i&-i)) {
		for (int j = y; j <= n; j += (j&-j)) {
			tree[i][j] += val;
		}
	}
}
ll sum(int x, int y) {
	ll ret = 0;
	for (int i = x; i > 0; i -= (i&-i)) {
		for (int j = y; j > 0; j -= (j&-j)) {
			ret += tree[i][j];
		}
	}
	return ret;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			update(i, j, a[i][j]);
		}
	}
	while (m--) {
		int w, x1, y1, x2, y2;
		scanf("%d", &w);
		if (w == 0) {
			scanf("%d %d %d", &x1, &y1, &x2);
			update(x1, y1, x2- a[x1][y1]);
			a[x1][y1] = x2;
		}
		else {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%lld\n", sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1-1, y1-1));
		}
	}

	return 0;
}