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

int p[1000002], r[1000002];

struct Union {
	// 초기에는 모두가 조상이 자기 자신
	Union(int n) {
		for (int i = 0; i < n + 1; i++) {
			p[i] = i;
		}
	}
	// 조상을 찾아서 리턴
	int find(int u) {
		if (p[u] == u) return u;
		return p[u] = find(p[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (r[u] == r[v]) {
			swap(u, v);
		}
		p[u] = v;
		if (r[u] == r[v]) {
			++r[v];
		}
	}
	bool isSameSet(int u, int v) {
		return find(u) == find(v);
	}
};


int main() {

	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	Union un(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			un.merge(b, c);
		}
		else {
			if (un.isSameSet(b, c)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}