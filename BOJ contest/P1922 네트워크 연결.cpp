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
#include <functional>
using namespace std;

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
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
	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (r[u] == r[v]) {
			swap(u, v);
		}
		p[u] = v;
		if (r[u] == r[v]) {
			r[v]++;
		}
	}
	bool isSameSet(int u, int v) {
		return find(u) == find(v);
	}
};

int n, m;
vector<tuple<int, int, int>> edges;

int main() {

	int from, to, cost;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		edges.push_back(mt(cost, from, to));
		edges.push_back(mt(cost, to, from));
	}

	sort(edges.begin(), edges.end());

	Union un(n);

	ll ret = 0;
	int t = 0;
	int i = 0;
	while (t < n-1) {
		
		tie(cost, from, to) = edges[i++];
		if (un.isSameSet(from, to)) {
			continue;
		}
		t++;
		ret += (ll)cost;
		un.merge(from, to);
	}
	
	printf("%lld\n", ret);

	return 0;
}