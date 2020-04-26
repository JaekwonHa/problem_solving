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

int main() {
	int n, m;

	auto man_node = [&](int x) {
		return 1 + x;
	};
	auto work_node = [&](int x) {
		return 1 + n + x + 1;
	};
	
	scanf("%d %d", &n, &m);

	MaximumFlow mf(n+m + 4, 0, n+m + 3);
	for (int i = 0; i < n; i++) {
		mf.add_edge_from_source(man_node(i), 2);
		int a, b;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			mf.add_edge(man_node(i), work_node(b), 1);
		}
	}
	for (int i = 1; i <= m; i++) mf.add_edge_to_sink(work_node(i), 1);

	printf("%d\n", mf.flow());
	return 0;
}

