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

int arr[501][501];

int main() {
	
	int T;
	scanf("%d", &T);
	while (T--) {
		int c, d, v;

		scanf("%d %d %d", &c, &d, &v);

		Dinic D(2 + 2 * (c + d));
		memset(arr, 0, sizeof(arr));

		char ch1, ch2;
		int idx1, idx2;
		for (int i = 0; i < v; i++) {
			scanf("\n%c%d %c%d", &ch1, &idx1, &ch2, &idx2);
			int from = 0, to = c + d;
			if (ch1 == 'C') from = c;
			if (ch2 == 'D') to = c + d + c;
			from += idx1;
			to += idx2;
			arr[from][to]++;
		}
		for (int i = 1; i <= c + d; i++) {
			for (int j = 1; j <= c + d; j++) {
				if (arr[i][c + d + j] > 0) {
					D.add_edge(i, c + d + j, arr[i][c + d + j]);
				}
			}
		}
		for (int i = 1; i <= c + d; i++) {
			D.add_edge(0, i, 1);
			D.add_edge(c + d + i, (c + d) * 2 + 1, 1);
		}
		printf("%d\n", D.max_flow(0, (c + d) * 2 + 1));

	}

	
	return 0;
}