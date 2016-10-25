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

vector<int> v[20001];
int visit[20001];
int ans;

void dfs(int n, int color) {
	visit[n] = color;
	for (auto a : v[n]) {
		if (visit[a]!=-1) {
			if (color == visit[a]) ans = 0;
			continue;
		}
		dfs(a, (color+1)%2);
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

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, from, to, start;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &from, &to);
			v[from].push_back(to);
			v[to].push_back(from);
		}

		ans = 2;
		memset(visit, -1, sizeof(visit));
		for (int i = 1; i <= n; i++) {
			if (visit[i] == -1) {
				dfs(i,0);
			}
		}
		if (ans == 2) printf("YES\n");
		else printf("NO\n");
	}
	

	return 0;
}