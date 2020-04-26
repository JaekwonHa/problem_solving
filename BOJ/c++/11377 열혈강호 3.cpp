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

struct Dinic {

	struct edge {
		int to, cap, rev;
		edge() {}
		edge(int a, int b, int c) :to(a), cap(b), rev(c) {}
	};
	vector<vector<edge>> G;
	vector<int> level;
	vector<int> iter;

	Dinic(int n) {
		G.resize(n);
		level.resize(n);
		iter.resize(n);
	}


	void add_edge(int from, int to, int cap)
	{
		edge e(to, cap, G[to].size());
		edge re(from, 0, G[from].size());
		G[from].push_back(e);
		G[to].push_back(re);
	}
	void bfs(int s) {
		std::fill(level.begin(), level.end(), -1);
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front();
			que.pop();
			for (int i = 0; i < G[v].size(); i++) {
				edge & e = G[v][i];
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f) {
		if (v == t) return f;
		for (int &i = iter[v]; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, std::min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t) {
		int flow = 0;
		while (true) {
			bfs(s);
			if (level[t] < 0) return flow;
			std::fill(iter.begin(), iter.end(), 0);
			int f;
			while ((f = dfs(s, t, INF)) > 0) {
				flow += f;
			}
		}
	}
};


int main() {
	int n, m, k;

	auto man_node = [&](int x) {
		return 2 + x;
	};
	auto work_node = [&](int x) {
		return 2 + n + x;
	};
	auto K_node = [&]() {
		return 1;
	};

	scanf("%d %d %d", &n, &m, &k);

	Dinic D(n + m + 5);
	D.add_edge(0, K_node(), k);
	for (int i = 0; i < n; i++) {
		D.add_edge(0, man_node(i), 1);
		D.add_edge(K_node(), man_node(i), 1);
		int a, b;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			D.add_edge(man_node(i), work_node(b), 1);
		}
	}
	for (int i = 1; i <= m; i++) D.add_edge(work_node(i), n + m + 4, 1);

	printf("%d\n", D.max_flow(0, n + m + 4));
	return 0;
}

