#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, K, ans;
vector<int> v[2001];
bool visit[2001];

void dfs(int n, int parent, int depth) {
	
	if (depth >= 5) {
		ans = 1;
		return;
	}
	for (int i = 0; i < v[n].size(); i++) {
		if (v[n][i] == parent || visit[v[n][i]]==true) continue;
		visit[v[n][i]] = true;
		dfs(v[n][i], n, depth + 1);
		visit[v[n][i]] = false;
	}
}

int main() {
	scanf("%d %d", &N, &K);
	
	int x, y;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	ans = 0;
	for (int i = 0; i < N; i++) {
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		dfs(i, i, 1);
		if (ans == 1) {
			break;
		}
	}

	printf("%d\n", ans);

	return 0;
}