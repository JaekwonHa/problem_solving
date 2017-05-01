#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

#define INF 987654321

int N, D, un[55];
char str[55];
int map[55][55];
int visit[55];

int dfs(int n,int depth) {
	visit[n] = 1;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (map[n][i] == 1 && visit[i] != 1)
			ret = max(ret, dfs(i, depth + 1));
	}
	return max(depth,ret);
}
int bfs(int n) {
	queue<int> q;
	q.push(n);
	visit[n] = 1;
	int depth = 0;
	bool more = false;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (map[cur][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = 1;
				more = true;
			}
		}
		if (more == true) depth++;
		more = false;
	}
	return depth;
}

int union_find(int x) {
	vector<int> q;
	while (un[x] != x) {
		if (un[x] != un[un[x]]) q.push_back(x);
		x = un[x];
	}
	while (!q.empty()) {
		un[q.back()] = x;
		q.pop_back();
	}
	return x;
}

void solveBFS() {
	int p, q, uc;
	scanf("%d %d", &N, &D);
	uc = N;
	for (int i = 0; i < N; i++) un[i] = i;
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == 'Y') {
				map[i][j] = 1;
				map[j][i] = 1;
				p = union_find(i);
				q = union_find(j);
				if (p != q) {
					if (p < q) un[q] = p;
					else un[p] = q;
					uc--;
				}
			}
		}
	}
	if (uc != 1) {
		printf("-1\n");
	}
	else {
		int depth;
		for (int i = 0; i < N; i++) {
			memset(visit, 0, sizeof(visit));
			depth = max(depth, bfs(i));
		}
		printf("%d\n", depth*D);
	}
}

void solveFloyd() {

	scanf("%d %d", &N, &D);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = INF;
			map[j][i] = INF;
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == 'Y') {
				map[i][j] = 1;
				map[j][i] = 1;
			}
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (map[i][j] > map[i][k] + map[k][j] || map[i][j] > map[j][k] + map[k][i]) {
					map[i][j] = map[i][k] + map[k][j];
					map[j][i] = map[i][k] + map[k][j];
				}
			}
		}
	}
	bool ok = true;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			ans = max(ans, map[i][j]);
			ans = max(ans, map[j][i]);
		}
	}
	if (ans == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans*D);
	}
}

int main() {

	solveBFS();
	

	return 0;
}