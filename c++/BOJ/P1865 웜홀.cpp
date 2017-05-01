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

vector<pair<int, int>> v[501];

bool bellman_ford(int start, int n) {
	bool cycle = false;
	int dist[501];
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[start] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto a : v[j]) {
				if (dist[a.first] > dist[j] + a.second) {
					dist[a.first] = dist[j] + a.second;
					if (i == n - 1) cycle = true;
				}
			}
		}
	}
	return cycle;
}

int main() {

	int T, n, m, w, from, to, cost;
	scanf("%d", &T);
	while (T--) {

		scanf("%d %d %d", &n, &m, &w);

		for (int i = 1; i <= n; i++) v[i].clear();

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &from, &to, &cost);
			v[from].push_back(make_pair(to, cost));
			v[to].push_back(make_pair(from, cost));
		}
		queue<int> q;
		for (int i = 0; i < w; i++) {
			scanf("%d %d %d", &from, &to, &cost);
			v[from].push_back(make_pair(to, -cost));
			q.push(to);
		}

		bool ok = false;
		while (!q.empty() && ok == false) {
			int start = q.front();
			q.pop();
			if (bellman_ford(start, n)) ok = true;
		}
		ok ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}