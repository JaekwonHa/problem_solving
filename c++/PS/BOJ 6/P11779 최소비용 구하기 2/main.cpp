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

int n, m;
vector<pair<int, int>> v[1001];

void DS(int start, int dest) {
	int d[1001];
	int p[1001];

	for (int i = 0; i <= n; i++) d[i] = INF, p[i]=-1;
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(mp(0, start));
	while (!pq.empty()) {
		int now, cost;
		tie(cost, now) = pq.top();
		pq.pop();
		cost = -cost;

		if (d[now] < cost) continue;

		for (auto a : v[now]) {
			int next = a.second;
			int nextC = d[now] + a.first;

			if (d[next] > nextC) {
				d[next] = nextC;
				pq.push(mp(-nextC, next));
				p[next] = now;
			}
		}
	}
	vector<int> path;
	path.push_back(dest);
	int t = dest;
	while (p[t] != -1) {
		path.push_back(p[t]);
		t = p[t];
	}
	printf("%d\n%d\n", d[dest], path.size());
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
}

int main() {
	int from, to, cost, start, dest;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(mp(cost, to));
	}
	scanf("%d %d", &start, &dest);
	DS(start, dest);

	return 0;
}