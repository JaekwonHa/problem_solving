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
#include <set>
#include <deque>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

struct Union {
	vector<int> p, r;
	Union(int n) : p(n + 1), r(n + 1, 1) {
		for (int i = 0; i < n + 1; i++) {
			p[i] = i;
		}
	}
	int find(int u) {
		if (p[u] == u) return u;
		return p[u] = find(p[u]);
	}
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return r[u];
		
		if (u != v) {
			p[v] = u;
			r[u] += r[v];
			r[v] = 1;
		}
		return r[u];
	}
	bool isSameSet(int u, int v) {
		return find(u) == find(v);
	}
	int getConnection(int u) {
		return r[u];
	}
};

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, idx=0, aa, bb;
		scanf("%d", &n);
		Union un(n + 1);
		map<string, int> m1;
		char a[21], b[21];
		for (int i = 0; i < n; i++) {
			scanf("%s %s", &a, &b);
			if (m1.count(a) == 0) {
				m1[a] = idx;
				idx++;
			}
			aa = m1[a];
			if (m1.count(b) == 0) {
				m1[b] = idx;
				idx++;
			}
			bb = m1[b];
			un.merge(aa, bb);

			printf("%d\n", un.getConnection(un.find(aa)));
		}
	}

	return 0;
}