#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

vector<vector<int>> g(100010, vector<int>());
/*
int minHeight(int n, vector<pair<int, int>> &edge) {
	if (n == 1) return 0;
	
	vector<int> res, d(n+1, 0);
	queue<int> q;
	
	//vector<vector<int>> g(n+1, vector<int>());
	
	// 그래프 g에다가 간선 추가하기
	for (auto a : edge) {
		g[a.first].push_back(a.second);
		g[a.second].push_back(a.first);
		d[a.first]++;
		d[a.second]++;
	}

	// 말단 노드 확인하고 추가하기
	for (auto a : d) {
		if (d[a] == 1) q.push(a);
	}
	while (n > 2) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int c = q.front();
			q.pop();
			n--;
			for (auto a : g[c]) {
				d[a]--;
				if (d[a] == 1) q.push(a);
			}
		}
	}
	while (!q.empty()) {
		res.push_back(q.front());
		q.pop();
	}
	return res.front();
}

int bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	int depth = 0;

	while (!q.empty()) {

		int c = q.front();
		q.pop();
		visit[c] = true;

		bool isMore = false;
		for (auto a : g[c]) {
			if (visit[a] == false) {
				q.push(a);
				isMore = true;
			}
		}
		if (isMore) depth++;
	}
	return depth;
}
*/
int depth, pos;
bool visit[100001];
void dfs(int n, int d) {
	if (depth < d) {
		pos = n;
		depth = d;
	}
	visit[n] = true;
	for (auto a : g[n]) {
		if (visit[a] == false) {
			dfs(a, d + 1);
		}
	}
}

int main() {
	int N,a,b;
	vector<pair<int, int>> edge;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		edge.push_back(make_pair(a, b));
	}
	for (auto a : edge) {
		g[a.first].push_back(a.second);
		g[a.second].push_back(a.first);
	}
	memset(visit, false, sizeof(visit));
	dfs(1,0);
	depth = 0;
	memset(visit, false, sizeof(visit));
	dfs(pos,0);

	if (depth % 2 == 0) depth = depth / 2;
	else depth = (depth + 1) / 2;
	cout << depth << endl;

	/*
	int start = minHeight(N, edge);
	cout << bfs(start) << endl;
	*/

	return 0;
}