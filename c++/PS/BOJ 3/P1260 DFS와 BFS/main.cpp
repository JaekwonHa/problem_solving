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

vector<int> v[1001];
bool visit[1001];

void dfs(int n) {
	printf("%d ", n);
	visit[n] = true;
	for (auto a : v[n]) {
		if (visit[a]) continue;
		dfs(a);
	}
}

void bfs(int n) {
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (visit[now] == true) continue;
		visit[now] = true;
		printf("%d ", now);
		for (auto a : v[now]) {
			int next = a;
			if (visit[next] == true) continue;
			q.push(next);
		}
	}
}

int main() {

	int n, m, from, to, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());

	memset(visit, false, sizeof(visit));
	dfs(start);
	printf("\n");
	memset(visit, false, sizeof(visit));
	bfs(start);
	printf("\n");

	return 0;
}