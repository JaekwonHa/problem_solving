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
#include <sstream>
using namespace std;

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다
// priority_queue 는 기본적으로 내림차순 정렬이다. 오름차순으로 하고 싶다면 priority_queue<int, vector<int>, greater<int>>
// queue에서 pop하기 전에는 반드시 empty인 경우를 체크하고 예외처리 해줘라


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

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

int rarr[300][300];
int larr[300][300];
int rnum = 0;
int lnum = 0;

int main() {
	
	int n;
	scanf("%d", &n);
	int m;
	int x, y;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		rarr[x][y] = -1;
		larr[x][y] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (rarr[i][j] == 0) {
				++rnum;
				for (int k = 0; k < n; k++) {
					if (i + k <= n && j + k <= n && rarr[i + k][j + k] == 0) rarr[i + k][j + k] = rnum;
					else break;
				}
			}
			if (larr[i][j] == 0) {
				++lnum;
				for (int k = 0; k < n; k++) {
					if (i + k <= n && j - k > 0 && larr[i + k][j - k] == 0) larr[i + k][j - k] = lnum;
					else break;
				}
			}
		}
	}
	Dinic D(rnum + lnum + 2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (rarr[i][j] != -1) D.add_edge(rarr[i][j], rnum + larr[i][j], 1);
		}
	}
	for (int i = 1; i <= rnum; i++) {
		D.add_edge(0, i, 1);
	}
	for (int i = 1; i <= lnum; i++) {
		D.add_edge(rnum + i, rnum + lnum + 1, 1);
	}

	printf("%d\n", D.max_flow(0, rnum + lnum + 1));
	return 0;
}