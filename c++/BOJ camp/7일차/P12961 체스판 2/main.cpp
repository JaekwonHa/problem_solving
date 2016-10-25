#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321

struct MaximumFlow {
	struct Edge {
		int to;
		int capacity;
		Edge *rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {
		}
	};
	int n;
	int source, sink;
	vector<vector<Edge *>> graph;
	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		graph.resize(n);
	};
	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, cap);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	void add_edge_from_source(int v, int cap) {
		add_edge(source, v, cap);
	}
	void add_edge_to_sink(int u, int cap) {
		add_edge(u, sink, cap);
	}
	int bfs() {
		vector<bool> check(n, false);
		vector<pair<int, int>> from(n, make_pair(-1, -1));
		queue<int> q;
		q.push(source);
		check[source] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
					q.push(graph[x][i]->to);
					check[graph[x][i]->to] = true;
					from[graph[x][i]->to] = make_pair(x, i);
				}
			}
		}
		if (!check[sink]) return 0;
		int x = sink;
		int c = graph[from[x].first][from[x].second]->capacity;
		while (from[x].first != -1) {
			if (c > graph[from[x].first][from[x].second]->capacity) {
				c = graph[from[x].first][from[x].second]->capacity;
			}
			x = from[x].first;
		}
		x = sink;
		while (from[x].first != -1) {
			Edge *e = graph[from[x].first][from[x].second];
			e->capacity -= c;
			e->rev->capacity += c;
			x = from[x].first;
		}
		return c;
	}
	int flow() {
		int ans = 0;
		while (true) {
			int f = bfs();
			if (f == 0) break;
			ans += f;
		}
		return ans;
	}
};

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	auto in_node = [&](int x, int y) {
		return 2 * (x*m + y);
	};
	auto out_node = [&](int x, int y) {
		return in_node(x, y) + 1;
	};

	MaximumFlow mf(n*m * 2 + 2, n*m * 2, n*m * 2 + 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				mf.add_edge(in_node(i, j), out_node(i, j), 1);
				if ((i + j) % 2 == 1) {
					if (i % 2 == 1) {
						mf.add_edge_from_source(in_node(i, j), 1);
						for (int k = 0; k < 4; k++) {
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (0 <= nx && nx < n && 0 <= ny && ny < m) {
								mf.add_edge(out_node(i, j), in_node(nx, ny), 1);
							}
						}
					}
					else {
						mf.add_edge_to_sink(out_node(i, j), 1);
						for (int k = 0; k < 4; k++) {
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (0 <= nx && nx < n && 0 <= ny && ny < m) {
								mf.add_edge(out_node(nx, ny), in_node(i, j), 1);
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", mf.flow());
	return 0;
}

