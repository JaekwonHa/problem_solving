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

int main() {

	int n, m, from, to, cost;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(make_pair(to, cost));
	}

	int dist[501];
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[1] = 0;

	bool cycle = false;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				if (dist[v[j][k].first] > dist[j] + v[j][k].second) {
					dist[v[j][k].first] = dist[j] + v[j][k].second;
					if (i == n - 1) cycle = true;
				}
			}
		}
	}
	if (cycle) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			printf("%d\n", dist[i] == INF ? -1 : dist[i]);
		}
	}

	return 0;
}