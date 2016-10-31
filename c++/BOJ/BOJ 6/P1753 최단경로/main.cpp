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
vector<pair<int, int>> v[20001];

void DS(int start) {
	int d[20001];
	int p[20001];

	for (int i = 0; i <= n; i++) d[i] = INF, p[i] = -1;
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
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}

int main() {
	int from, to, cost, start, dest;
	scanf("%d %d", &n, &m);
	scanf("%d", &start);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(mp(cost, to));
	}
	
	DS(start);

	return 0;
}