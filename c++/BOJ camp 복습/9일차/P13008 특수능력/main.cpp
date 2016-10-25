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

int n, m, c;
vector<tuple<int, int, int>> graph;
int dist[51][51];
int d[1001][51];

int main() {

	scanf("%d %d %d", &n, &m, &c);
	int from, to, cost;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}


	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		graph.push_back(mt(from, to, cost));
		dist[from][to] = min(dist[from][to], cost);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		d[0][i] = dist[i][n];
	}

	for (int k = 1; k <= c; k++) {
		for (int i = 1; i <= n; i++) {
			d[k][i] = d[k - 1][i];
			for (int j = 0; j < m; j++) {
				tie(from, to, cost) = graph[j];
				d[k][i] = min(d[k][i], dist[i][from] - cost + d[k - 1][to]);
			}
		}
	}

	printf("%d\n", d[c][1]);

	return 0;
}