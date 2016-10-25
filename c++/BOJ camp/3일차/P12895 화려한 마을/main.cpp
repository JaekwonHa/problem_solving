#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAXN 400040
#define INF 987654321
#define p 1000000007
typedef long long ll;


char ch;
int n, m, q, idx = 1, seg[MAXN], lazy[MAXN], stamp[MAXN];

void makeTree() {
	while (idx < n) {
		idx <<= 1;
	}
	for (int i = 1; i < idx + n; i++) {
		seg[i] = 1;
		stamp[i] = -1;
	}
}

int query(int lo, int hi, int node, int x, int y) {
	if (y < lo || hi < x) {
		return 0;
	}
	if (lazy[node]) {
		if (x != y) {
			if (stamp[node * 2] < stamp[node]) {
				lazy[node * 2] = lazy[node];
				seg[node * 2] = seg[node];
				stamp[node * 2] = stamp[node];
			}
			if (stamp[node * 2 + 1] < stamp[node]) {
				lazy[node * 2 + 1] = lazy[node];
				seg[node * 2 + 1] = seg[node];
				stamp[node * 2 + 1] = stamp[node];
			}
		}
		lazy[node] = 0;
		stamp[node] = -1;
	}
	if (lo <= x && y <= hi) {
		return seg[node];
	}
	int mid = (x + y) / 2;
	return query(lo, hi, node * 2, x, mid) | query(lo, hi, node * 2 + 1, mid + 1, y);
}

int update(int lo, int hi, int node, int x, int y, int color, int when) {
	if (y < lo || hi < x) {
		return seg[node];
	}
	if (lazy[node]) {
		if (x != y) {
			if (stamp[node * 2] < stamp[node]) {
				lazy[node * 2] = lazy[node];
				seg[node * 2] = seg[node];
				stamp[node * 2] = stamp[node];
			}
			if (stamp[node * 2 + 1] < stamp[node]) {
				lazy[node * 2 + 1] = lazy[node];
				seg[node * 2 + 1] = seg[node];
				stamp[node * 2 + 1] = stamp[node];
			}
		}
		lazy[node] = 0;
		stamp[node] = -1;
	}
	if (lo <= x && y <= hi) {
		seg[node] = color;
		lazy[node] = color;
		stamp[node] = when;
		return seg[node];
	}
	int mid = (x + y) / 2;
	return seg[node] = update(lo, hi, node * 2, x, mid, color, when) | update(lo, hi, node * 2 + 1, mid + 1, y, color, when);
}


int main() {
	scanf("%d %d %d", &n, &m, &q);
	makeTree();
	for (int i = 0; i < q; i++) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'C') {
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			if (x > y) {
				swap(x, y);
			}
			update(x - 1, y - 1, 1, 0, idx - 1, 1 << (c - 1), i);
		}
		else {
			int x, y;
			scanf("%d %d", &x, &y);
			if (x > y) {
				swap(x, y);
			}
			int ret = query(x - 1, y - 1, 1, 0, idx - 1);
			int ans = 0;
			while (ret) {
				if (ret & 1) ans++;
				ret /= 2;
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}